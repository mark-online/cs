#include "RandomDungeonPCH.h"
#include <gideon/cs/randun/RandomDungeonConstructor.h>
#include <gideon/cs/datatable/RegionTable.h>
#include <gideon/cs/datatable/RegionCoordinates.h>
#include <gideon/cs/datatable/RegionSpawnTable.h>
#include <gideon/cs/datatable/NpcTable.h>
#include <gideon/cs/shared/data/TreasureInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include "esut/Random.h"
#include <sne/core/memory/MemoryPoolMixin.h>
#include <boost/algorithm/string/replace.hpp>
#include <iostream>
#include <ctime>

namespace gideon { namespace randun {

namespace {

typedef sne::core::Vector<std::string> Strings;

const float mapScale = 2.0f;
const float xTileSize = 6.0f;
const float yTileSize = 6.0f;
const float zTileSize = 8.4f;
const float xTileHalfSize = xTileSize / 2.0f;
const float yTileHalfSize = yTileSize / 2.0f;
const float zTileHalfSize = zTileSize / 2.0f;

const float OWEST = 0.0f;
const float ONORTH = 0.1f;
const float OEAST = 0.2f;
const float OSOUTH = 0.3f;

const std::string s_cc = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_";
const std::string s_mults = ".,;|{}[]";


inline float roundf(float val)
{
    //return floorf(val + 0.5f);

    const int integral = int(val);
    const float mantissa = val - integral;
    return (mantissa < 0.5f) ? float(integral) : integral + 1.0f;
}


inline std::string chrMuliply(char c, size_t count)
{
    return std::string(count, c);
}


/// split("a+b+cd", '+') == { "a", "b", "cd" }
// 출처: http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
inline Strings split(const std::string& str, char delimiter)
{
    Strings tokens;

    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiter, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiter, lastPos);

    while ((std::string::npos != pos) || (std::string::npos != lastPos)) {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiter, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiter, lastPos);
    }
    return tokens;
}


inline std::string getTitleFilename(RandomDungeonConstructor::TileType tileType,
    const RandomDungeonConstructor::TileInfo& tileInfo, const ExportParameters& params)
{
    uint16_t tileCount = 1;
    switch (tileType) {
    case RandomDungeonConstructor::TFLOOR:
        tileCount = params.floorCount_;
        break;
    case RandomDungeonConstructor::TWALL:
        tileCount = params.wallCount_;
        break;
    case RandomDungeonConstructor::TCORNER:
        tileCount = params.cornerCount_;
        break;
    case RandomDungeonConstructor::TCORRIDOR:
        tileCount = params.corridorCount_;
        break;
    case RandomDungeonConstructor::TCORRIDORX:
        tileCount = params.corridorCrossCount_;
        break;
    case RandomDungeonConstructor::TCORRIDORCORNER:
        tileCount = params.corridorCornerCount_;
        break;
    case RandomDungeonConstructor::TCORRIDOREND:
        tileCount = params.corridorEndCount_;
        break;
    case RandomDungeonConstructor::TCORRIDORT:
        tileCount = params.corridorTCrossCount_;
        break;
    }
    assert(tileCount >=1 );

    return tileInfo.name_ + "_" + char('1' + (esut::random() % tileCount));
}

inline std::string getFullTileTemplate(const RandomDungeonConstructor::TileInfo& tileInfo)
{
    std::ostringstream oss;
    oss <<
        "new GideonTSStatic(DTile_" << tileInfo.name_ << ") {\n"
        "    playAmbient = \"1\";\n"
        "    meshCulling = \"0\";\n"
        "    originSort = \"0\";\n"
        "    collisionType = \"Collision Mesh\";\n"
        "    decalType = \"Collision Mesh\";\n"
        "    allowPlayerStep = \"1\";\n"
        "    renderNormals = \"0\";\n"
        "    forceDetail = \"-1\";\n"
        "    position = \"0 0 -10000\";\n"
        "    rotation = \"0 0 1 0\";\n"
        //"    scale = \"" << mapScale << " " << mapScale << " " << mapScale << "\";\n"
        "    scale = \"1 1 1\";\n"
        "    cameraIgnores = \"0\";\n"
        "    canSave = \"1\";\n"
        "    canSaveDynamicFields = \"1\";\n"
        "    customAmbientLighting = \"0 0 0 1\";\n"
        "    enabled = \"1\";\n"
        "    receiveLMLighting = \"1\";\n"
        "    receiveSunLight = \"1\";\n"
        "    useCustomAmbientLighting = \"0\";\n"
        "};\n";
    return oss.str();
}


inline std::string getTileTemplate(float tileTypef,
    const RandomDungeonConstructor::TileInfo& tileInfo, int row, int column,
    const Position& pos, const ExportParameters& params)
{
    const RandomDungeonConstructor::TileType tileType =
        RandomDungeonConstructor::TileType(int(tileTypef));

    const float u = 3.0f - roundf((tileTypef - tileType) * 10);
    const float rotation = ((u * 90) + roundf(tileInfo.degrees_)) * -1.0f;

    std::ostringstream oss;
    oss << 
        "new GideonTSStatic(DTile_" << column << "_" << row << " : DTile_" << tileInfo.name_ << ") {\n"
        "    shapeName = \"art/shapes/Gideon/random_dungeon/" <<
            params.baseFolder_ << "/" << getTitleFilename(tileType, tileInfo, params) << ".dts\";\n"
        "    position = \"" << pos.x_ << " " << pos.y_ << " " << pos.z_ << "\";\n"
        "    rotation = \"0 0 1 " << rotation << "\";\n"
        "};\n";
    return oss.str();
}


inline std::string getFloorTemplate(int level, const std::string& tiles)
{
    std::ostringstream oss;
    oss <<
        "new SimGroup(DFloor_" << level << ") {\n"
        "    canSaveDynamicFields = \"1\";\n"
        "    enabled = \"1\";\n"
        "\n"
        << tiles <<
        "};\n";
    return oss.str();
}


inline std::string getSpawnPointTemplate(const Position& pos)
{
    std::ostringstream oss;
    oss <<
        "new SpawnSphere(LocalDropPoint) {\n"
        "    autoSpawn = \"0\";\n"
        "    radius = \"1\";\n"
        "    sphereWeight = \"1\";\n"
        "    indoorWeight = \"1\";\n"
        "    outdoorWeight = \"1\";\n"
        "    dataBlock = \"SpawnSphereMarker\";\n"
        "    position = \"" << pos.x_ << " " << pos.y_ << " " << pos.z_ << "\";\n"
        "    rotation = \"0 0 1 0\";\n"
        "    scale = \"1 1 1\";\n"
        "    cameraIgnores = \"0\";\n"
        "    canSave = \"1\";\n"
        "    canSaveDynamicFields = \"1\";\n"
        "    enabled = \"1\";\n"
        "    homingCount = \"0\";\n"
        "    lockCount = \"0\";\n"
        "};\n";
    return oss.str();
}


inline const char* getMissionTemplate()
{
    return
        "new SimGroup(MissionGroup) {\n"
        "    canSaveDynamicFields = \"1\";\n"
        "      enabled = \"1\";\n"
        "          terrainWidth = \"gideon_terrain_width\";\n"
        "          terrainHeight = \"gideon_terrain_height\";\n"
        "    new LevelInfo(theLevelInfo) {\n"
        "        nearClip = \"0.1\";\n"
        "        visibleDistance = \"500\";\n"
        "        decalBias = \"0.0015\";\n"
        "        fogColor = \"0.494118 0.494118 0.494118 1\";\n"
        "        fogDensity = \"0.04\";\n"
        "        fogDensityOffset = \"10\";\n"
        "        fogAtmosphereHeight = \"0\";\n"
        "        canvasClearColor = \"201 199 201 255\";\n"
        "        advancedLightmapSupport = \"0\";\n"
        "        soundAmbience = \"AudioAmbienceDefault\";\n"
        "        soundDistanceModel = \"Linear\";\n"
        "        canSave = \"1\";\n"
        "        canSaveDynamicFields = \"1\";\n"
        "          enabled = \"1\";\n"
        "          LevelName = \"RanomDungeon\";\n"
        "    };\n"
        "    new ScatterSky(ScatterSky01) {\n"
        "        skyBrightness = \"50\";\n"
        "        mieScattering = \"0.0045\";\n"
        "        rayleighScattering = \"0.0035\";\n"
        "        sunScale = \"0.654902 0.654902 0.654902 1\";\n"
        "        ambientScale = \"0.294118 0.294118 0.294118 1\";\n"
        "        fogScale = \"0.494118 0.494118 0.494118 1\";\n"
        "        exposure = \"1.4\";\n"
        "        zoffset = \"0\";\n"
        "        InCaveAmbient = \"0\";\n"
        "        ChangetomAmbientScale = \"0.223529 0.223529 0.223529 1\";\n"
        "        azimuth = \"0\";\n"
        "        elevation = \"40\";\n"
        "        moonAzimuth = \"0\";\n"
        "        moonElevation = \"45\";\n"
        "        castShadows = \"1\";\n"
        "        brightness = \"1.2\";\n"
        "        flareType = \"LightFlareExample2\";\n"
        "        flareScale = \"1\";\n"
        "        nightColor = \"0.0196078 0.0117647 0.109804 1\";\n"
        "        nightFogColor = \"0.0196078 0.0117647 0.109804 1\";\n"
        "        moonEnabled = \"1\";\n"
        "        moonMat = \"Moon_Glow_Mat\";\n"
        "        moonScale = \"0.2\";\n"
        "        moonLightColor = \"0.192157 0.192157 0.192157 1\";\n"
        "        useNightCubemap = \"1\";\n"
        "        nightCubemap = \"NightCubemap\";\n"
        "        attenuationRatio = \"0 1 1\";\n"
        "        shadowType = \"PSSM\";\n"
        "        texSize = \"1024\";\n"
        "        overDarkFactor = \"16000 8000 4000 800\";\n"
        "        shadowDistance = \"300\";\n"
        "        shadowSoftness = \"0.1\";\n"
        "        numSplits = \"4\";\n"
        "        logWeight = \"0.91\";\n"
        "        fadeStartDistance = \"0\";\n"
        "        lastSplitTerrainOnly = \"0\";\n"
        "        representedInLightmap = \"0\";\n"
        "        shadowDarkenColor = \"0 0 0 -1\";\n"
        "        includeLightmappedGeometryInShadow = \"0\";\n"
        "        position = \"-674.999 -270.253 1738.71\";\n"
        "        rotation = \"1 0 0 0\";\n"
        "        scale = \"1 1 1\";\n"
        "        cameraIgnores = \"0\";\n"
        "        canSave = \"1\";\n"
        "        canSaveDynamicFields = \"1\";\n"
        "    };\n"
        "    new SFXEmitter() {\n"
        "        fileName = \"art/sound/gideon/RegionSound/Dungeon_BGM.ogg\";\n"
        "        playOnAdd = \"1\";\n"
        "        useTrackDescriptionOnly = \"0\";\n"
        "        isLooping = \"1\";\n"
        "        isStreaming = \"1\";\n"
        "        volume = \"0.5\";\n"
        "        pitch = \"1\";\n"
        "        fadeInTime = \"0\";\n"
        "        fadeOutTime = \"0\";\n"
        "        is3D = \"0\";\n"
        "        referenceDistance = \"1\";\n"
        "        maxDistance = \"100\";\n"
        "        scatterDistance = \"0 0 0\";\n"
        "        coneInsideAngle = \"360\";\n"
        "        coneOutsideAngle = \"360\";\n"
        "        coneOutsideVolume = \"1\";\n"
        "        position = \"0 0 0\";\n"
        "        rotation = \"1 0 0 0\";\n"
        "        scale = \"100 100 100\";\n"
        "        cameraIgnores = \"0\";\n"
        "        canSave = \"1\";\n"
        "        canSaveDynamicFields = \"1\";\n"
        "    };\n"
        "    new SimGroup(PlayerDropPoints) {\n"
        "        canSaveDynamicFields = \"1\";\n"
        "        enabled = \"1\";\n"
        "        gideon_spawns = \"0\";\n"
        "    };\n"
        "    new SimGroup(Dungeon) {\n"
        "        canSaveDynamicFields = \"1\";\n"
        "        enabled = \"1\";\n"
        "        gideon_tiles = \"0\";\n"
        "    };\n"
        "};\n";
}


inline std::string ftoa(float f)
{
    std::ostringstream oss;
    oss << f;
    return oss.str();
}


std::string makeMission(float terrainWidth, float terrainHeight,
    const std::string& missionTemplate, const std::string& floor, const std::string& spawnPoint)
{
    std::string mission;
    mission.reserve(40000);
    mission = missionTemplate;

    boost::replace_first(mission, "gideon_terrain_width", ftoa(terrainWidth));
    boost::replace_first(mission, "gideon_terrain_height", ftoa(terrainHeight));
    boost::replace_first(mission, "gideon_tiles = \"0\";", floor);
    boost::replace_first(mission, "gideon_spawns = \"0\";", spawnPoint);
    return mission;
}


const std::string emptyString;


/**
* @class RandomDungeonRegionTable
*/
class RandomDungeonRegionTable : public datatable::RegionTable,
    public sne::core::ThreadSafeMemoryPoolMixin<RandomDungeonRegionTable>
{
public:
    void addRegion(RegionCode regionCode) {
        regionMap_.insert(
            RegionMap::value_type(regionCode, datatable::RegionTemplate(regionCode, 0, 0)));
    }

private:
    virtual const datatable::RegionTemplate* getRegion(RegionCode code) const {
        const RegionMap::const_iterator pos = regionMap_.find(code);
        if (pos != regionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

private:
    virtual const RegionMap& getRegionMap() const {
        return regionMap_;
    }

    virtual const datatable::RegionTemplate* getRegionByQuestMissionCode(QuestMissionCode /*missionCode*/) const {
        assert(false && "DON'T CALL ME!");
        return nullptr;
    }

    virtual const std::string& getLastError() const {
        return emptyString;
    }

    virtual bool isLoaded() const {
        return true;
    }

private:
    RegionMap regionMap_;
};


/**
* @class RandomDungeonRegionCoordinates
*/
class RandomDungeonRegionCoordinates : public datatable::RegionCoordinates,
    public sne::core::ThreadSafeMemoryPoolMixin<RandomDungeonRegionCoordinates>
{
public:
    void addCoordinates(RegionCode regionCode, const Position& position) {
        const float margin = 0.8f;
        datatable::CoordinatesTemplate coord(regionCode, position,
            (((std::max)(xTileHalfSize, yTileHalfSize) * mapScale) - margin));
        coord.center_.z_ += 0.5f;
        coordinatesMap_[regionCode].push_back(coord);
    }

private:
    virtual const CoordinatesList* getCoordinates(RegionCode code) const {
        const CoordinatesMap::const_iterator pos = coordinatesMap_.find(code);
        if (pos != coordinatesMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

private:
    virtual const CoordinatesMap& getCoordinatesMap() const {
        return coordinatesMap_;
    }

    virtual const std::string& getLastError() const {
        return emptyString;
    }

    virtual bool isLoaded() const {
        return true;
    }

private:
    CoordinatesMap coordinatesMap_;
};


/**
* @class RandomDungeonNpcSpawnTable
*/
class RandomDungeonNpcSpawnTable : public datatable::RegionSpawnTable,
    public sne::core::ThreadSafeMemoryPoolMixin<RandomDungeonNpcSpawnTable>
{
    typedef sne::core::HashMap<RegionCode, Spawns> RegionSpawnMap;

public:
    virtual ~RandomDungeonNpcSpawnTable() {
    }

    void addSpawn(RegionCode regionCode, const RegionSpawnTemplate& baseSpawnTemplate) {
        RegionSpawnTemplate rst;
        rst.regionCode_ = regionCode;
        rst.entityCode_ = baseSpawnTemplate.entityCode_;
        rst.pool_ = 1;
        rst.minSpawnDelay_ = 100;
        rst.maxSpawnDelay_ = 1000;
        regionNpcSpawnMap_[regionCode].push_back(rst);
    }

private:
    virtual const Spawns* getSpawns(RegionCode regionCode) const {
        const RegionSpawnMap::const_iterator pos =
            regionNpcSpawnMap_.find(regionCode);
        if (pos != regionNpcSpawnMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const std::string& getLastError() const {
        static std::string empty;
        return empty;
    }

    virtual bool isLoaded() const {
        return true;
    }

private:
    RegionSpawnMap regionNpcSpawnMap_;
};


RandomDungeonConstructor::SpawnTemplates getNpcSpawnTemplates(
    const datatable::RegionSpawnTable::Spawns& spawns,
    MonsterGrade monsterGradeBegin, MonsterGrade monsterGradeEnd,
    const datatable::NpcTable& npcTable)
{
    RandomDungeonConstructor::SpawnTemplates spawnTemplates;
    spawnTemplates.reserve(spawns.size());
    for (const RegionSpawnTemplate& spawn : spawns) {
        const NpcCode npcCode = spawn.entityCode_;
        const datatable::NpcTemplate* npcTemplate = npcTable.getNpcTemplate(npcCode);
        if (! npcTemplate) {
            continue;
        }

        const MonsterGrade grade = npcTemplate->getMonsterGrade();
        if ((monsterGradeBegin <= grade) && (grade <= monsterGradeEnd)) {
            spawnTemplates.push_back(spawn);
        }
    }
    return spawnTemplates;
}


const RegionSpawnTemplate* getSpecialTreasureSpawnTemplate(
    const datatable::RegionSpawnTable::Spawns& spawns)
{
    for (const RegionSpawnTemplate& spawn : spawns) {
        const DataCode dataCode = spawn.entityCode_;
        const CodeType codeType = getCodeType(dataCode);
        if (codeType != ctTreasure) {
            continue;
        }

        if (spawn.pool_ == 1) {
            return &spawn;
        }
    }
    return nullptr;
}


RandomDungeonConstructor::SpawnTemplates getTreasureSpawnTemplates(
    const datatable::RegionSpawnTable::Spawns& spawns)
{
    RandomDungeonConstructor::SpawnTemplates spawnTemplates;
    spawnTemplates.reserve(spawns.size());

    for (const RegionSpawnTemplate& spawn : spawns) {
        const DataCode dataCode = spawn.entityCode_;
        const CodeType codeType = getCodeType(dataCode);
        if (codeType != ctTreasure) {
            continue;
        }

        if (spawn.pool_ > 1) {
            spawnTemplates.push_back(spawn);
        }
    }
    return spawnTemplates;
}

} // namespace

// = RandomDungeonConstructor

RandomDungeonConstructor::RandomDungeonConstructor(uint16_t columns, uint16_t rows, uint16_t baseZ) :
    totalColumns_(columns),
    totalRows_(rows),
    xOffset_(0.0f),
    yOffset_(0.0f),
    zOffset_(baseZ),
    actBrush_(TTAKEN),
    actLevel_(0)
{
    tileData_[TFREE] = TileInfo("", 0);
    tileData_[TTAKEN] = TileInfo("", 0);
    tileData_[TFLOOR] = TileInfo("floor", -90, TCOLUMN, TCOLUMNBR, TCOLUMNINF);
    tileData_[TWALL] = TileInfo("wall", -90, TDOOR, TBAY, TTORCH);
    tileData_[TCORNER] = TileInfo("corner", -90);
    tileData_[TDOOR] = TileInfo("wall_door", -90, TWALL, TBAY, TTORCH);
    tileData_[TTORCH] = TileInfo("wall_torch", -90, TWALL, TDOOR, TBAY);
    tileData_[TBAY] = TileInfo("wall_bay", -90, TWALL, TDOOR, TTORCH);
    tileData_[TCOLUMN] = TileInfo("column", -90, TFLOOR, TCOLUMNBR, TCOLUMNINF);
    tileData_[TCOLUMNBR] = TileInfo("column_broken", -90, TFLOOR, TCOLUMN, TCOLUMNINF);
    tileData_[TCOLUMNINF] = TileInfo("infected_column", -90, TFLOOR, TCOLUMN, TCOLUMNBR);
    tileData_[TCORRIDORSML] = TileInfo("corridor_small", -90, TCORRIDOR, TCORRIDORDOOR);
    tileData_[TCORRIDORXSML] = TileInfo("corridor_small_cros", -90, TCORRIDORX);
    tileData_[TCORRIDOR] = TileInfo("corridor", -90, TCORRIDORSML, TCORRIDORDOOR);
    tileData_[TCORRIDORX] = TileInfo("corridor_cross", -90, TCORRIDORXSML);
    tileData_[TCORRIDORCORNER] = TileInfo("corridor_corner", -90);
    tileData_[TCORRIDOREND] = TileInfo("corridor_end", 90);
    tileData_[TCORRIDORT] = TileInfo("corridor_t_cross", -90);
    tileData_[TCORRIDORDOOR] = TileInfo("corridor_door", -90, TCORRIDORSML, TCORRIDOR);

    for (int i = TCORRIDORDOOR + 1; i < TCOUNT; ++i) {
        tileData_[i] = TileInfo();
    }

    const float terrainWidth = totalColumns_ * xTileSize * mapScale;
    const float terrainHeight = totalRows_ * yTileSize * mapScale;

    xOffset_ = -(terrainWidth / 2);
    yOffset_= -(terrainHeight / 2);
}


RandomDungeonConstructor::~RandomDungeonConstructor()
{
}


void RandomDungeonConstructor::generate(uint16_t genLength, uint16_t genSteps)
{
    initMap();

    int16_t column = int16_t(esut::randomf() * (totalColumns_ / 2) + (totalColumns_ / 4));
    int16_t row = int16_t(esut::randomf() * (totalRows_ / 2) + (totalRows_ / 4));
    map_[row][column] = TTAKEN;

    int16_t e = 0;
    uint16_t step = 0;
    while (step < genSteps) {
        const int c = int(esut::randomf() * genLength);
        switch (c) {
        case 0:
            ++e;
            if (e > 3) {
                e = e - 4;
            }
        case 1:
            --e;
            if (e < 0) {
                e = e * 1 + 4;
            }
        }

        switch (e) {
        case 0:
            --row;
            if (row < 0) {
                row = 0;
            }
            break;
        case 1:
            ++column;
            if (column >= totalColumns_) {
                column = totalColumns_ - 1;
            }
            break;
        case 2:
            ++row;
            if (row >= totalRows_) {
                row = totalRows_ - 1;
            }
            break;
        case 3:
            --column;
            if (column < 0) {
                column = 0;
            }
            break;
        }
        map_[row][column] = float(actBrush_);
        //std::cout << "(" << row << "," << column << ") = " << actBrush_ << "\n";
        ++step;
    }

    refreshMap();
}


void RandomDungeonConstructor::importDe(const std::string& de)
{
    initMap();

    uncompressMap(de);
    refreshMap();
}


std::string RandomDungeonConstructor::exportDe()
{
    return compressMap();
}


std::string RandomDungeonConstructor::exportMission(const ExportParameters& params)
{
    SpawnPoint spawnPoint;
    spawnPoint.level_ = actLevel_;

    std::string tiles;
    tiles.reserve(10000);
    sne::core::Set<TileType> usedTileTypes;

    for (int16_t row = 0; row < totalRows_; ++row) {
        for (int16_t column = 0; column < totalColumns_; ++column) {
            const TileType tileType = TileType(int(map_[row][column]));
            const TileInfo& tileInfo = tileData_[tileType];
            if (tileType > TFREE) {
                if (usedTileTypes.find(tileType) == usedTileTypes.end()) {
                    usedTileTypes.insert(tileType);
                    tiles += getFullTileTemplate(tileInfo);

                    if (isCharacterSpawnable(tileType)) {
                        if (! spawnPoint.isValid()) {
                            spawnPoint.row_ = row;
                            spawnPoint.column_ = column;
                        }
                    }
                }
                const Position position = getPosition(row, column, actLevel_);
                tiles += getTileTemplate(map_[row][column], tileInfo, row, column, position, params);
            }
        }
    }

    const float terrainWidth = totalColumns_ * yTileSize * mapScale;
    const float terrainHeight = totalRows_ * yTileSize * mapScale;

    Position spawnPosition;
    if (spawnPoint.isValid()) {
        spawnPosition =
            getPosition(spawnPoint.row_, spawnPoint.column_, spawnPoint.level_);
    }

    const std::string missionTemplate =
        params.missionTemplate_.empty() ? getMissionTemplate() : params.missionTemplate_;

    return makeMission(terrainWidth, terrainHeight, missionTemplate,
        getFloorTemplate(actLevel_, tiles), getSpawnPointTemplate(spawnPosition));
}


MapInfo RandomDungeonConstructor::getMapInfo(MapCode mapCode, uint16_t sectorLength) const
{
    const uint16_t totalLevels = 2;
    const float terrainWidth = totalColumns_ * xTileSize * mapScale; // x
    const float terrainHeight = totalRows_ * yTileSize * mapScale; // y
    const float terrainDepth = roundf(zOffset_ + (totalLevels * zTileSize * mapScale)); // z

    MapInfo mapInfo;
    mapInfo.mapCode_ = mapCode;
    mapInfo.originZ_ = int32_t(zOffset_); //int32_t(totalSize.z_ / 2);
    mapInfo.xSectorCount_ = int32_t((terrainWidth + sectorLength) / sectorLength);
    if ((mapInfo.xSectorCount_ % 2) == 0) {
        ++mapInfo.xSectorCount_;
    }
    mapInfo.ySectorCount_ = int32_t((terrainHeight  + sectorLength) / sectorLength);
    if ((mapInfo.ySectorCount_ % 2) == 0) {
        ++mapInfo.ySectorCount_;
    }
    mapInfo.zSectorCount_ = int32_t((terrainDepth  + sectorLength) / sectorLength);
    if ((mapInfo.zSectorCount_ % 2) == 0) {
        ++mapInfo.zSectorCount_;
    }
    mapInfo.sectorLength_ = sectorLength;

    assert(mapInfo.isValid());
    return mapInfo;
}


// TODO: 맵 분석
// TODO: 보스 스폰
// TODO: 몬스터 집단화
// TODO: 지역이 중복되지 않도록 수정
bool RandomDungeonConstructor::analyze(const datatable::RegionSpawnTable* baseSpawnTable,
    const datatable::NpcTable* npcTable)
{
    const int bossMinDistance = (std::min)((std::min)(totalColumns_, totalRows_) / 2, 3);
    const int monsterMinDistance = 1;
    typedef sne::core::Set<SpawnPoint> SpawnPointSet;

    const datatable::RegionSpawnTable::Spawns* spawns = nullptr;
    if (baseSpawnTable != nullptr) {
        spawns = baseSpawnTable->getSpawns(invalidRegionCode);
        if (! spawns) {
            return false;
        }
    }

    const SpawnPoint characterSpawnPoint = getCharacterSpawnPoint();
    if (! characterSpawnPoint.isValid()) {
        return false;
    }

    regionTable_ = std::make_unique<RandomDungeonRegionTable>();
    regionCoordinates_ = std::make_unique<RandomDungeonRegionCoordinates>();
    spawnTable_ = std::make_unique<RandomDungeonNpcSpawnTable>();

    const Position characterSpawnPosition = getPosition(characterSpawnPoint.row_,
        characterSpawnPoint.column_, characterSpawnPoint.level_);

    {
        const RegionCode characterSpawnRegionCode = makeRegionCode(rtCharacterSpawn, 1);
        static_cast<RandomDungeonRegionTable&>(*regionTable_).
            addRegion(characterSpawnRegionCode);
        static_cast<RandomDungeonRegionCoordinates&>(*regionCoordinates_).
            addCoordinates(characterSpawnRegionCode, characterSpawnPosition);
    }

    {
        const RegionCode graveRegionCode = makeRegionCode(rtGrave, 1);
        static_cast<RandomDungeonRegionTable&>(*regionTable_).addRegion(graveRegionCode);
        static_cast<RandomDungeonRegionCoordinates&>(*regionCoordinates_).
            addCoordinates(graveRegionCode, characterSpawnPosition);
    }

    {
        const RegionCode caoGraveRegionCode = makeRegionCode(rtCaoGrave, 1);
        static_cast<RandomDungeonRegionTable&>(*regionTable_).addRegion(caoGraveRegionCode);
        static_cast<RandomDungeonRegionCoordinates&>(*regionCoordinates_).
            addCoordinates(caoGraveRegionCode, characterSpawnPosition);
    }

    if ((! spawns) || (! npcTable)) {
        return true;
    }

    uint16_t regionIndex = 0;
    SpawnPointSet spawnPointSet;
    spawnPointSet.insert(characterSpawnPoint);

    const RegionSpawnTemplate* specialTreasureSpawn = getSpecialTreasureSpawnTemplate(*spawns);
    const SpawnTemplates bossSpawns = getNpcSpawnTemplates(*spawns, mgBoss, mgMutantBoss, *npcTable);
    for (const RegionSpawnTemplate& spawnTemplate : bossSpawns) {
        for (int32_t spawnCount = 0, missCount = 0; spawnCount < spawnTemplate.pool_;) {
            const SpawnPoint spawnPoint = getRandomSpawnPoint();
            const TileType tileType = TileType(int(map_[spawnPoint.row_][spawnPoint.column_]));
            if (isNpcSpawnable(tileType) && (spawnPointSet.find(spawnPoint) == spawnPointSet.end())) {
                if (isNpcSpawnable(characterSpawnPoint, spawnPoint, bossMinDistance)) {
                    spawnPointSet.insert(spawnPoint);
                    addSpawnTemplate(++regionIndex, spawnPoint, spawnTemplate);
                    if (specialTreasureSpawn != nullptr) {
                        addSpawnTemplate(++regionIndex, spawnPoint, *specialTreasureSpawn,
                            rtTreasure);
                    }
                    ++spawnCount;
                    continue;
                }
            }
            ++missCount;
            if (missCount > (spawnTemplate.pool_ * 10)) {
                break;
            }
        }
    }

    const SpawnTemplates monsterSpawns = getNpcSpawnTemplates(*spawns, mgInfant, mgEvolution, *npcTable);
    for (const RegionSpawnTemplate& spawnTemplate : monsterSpawns) {
        for (int32_t spawnCount = 0, missCount = 0; spawnCount < spawnTemplate.pool_;) {
            const SpawnPoint spawnPoint = getRandomSpawnPoint();
            const TileType tileType = TileType(int(map_[spawnPoint.row_][spawnPoint.column_]));
            if (isNpcSpawnable(tileType) && (spawnPointSet.find(spawnPoint) == spawnPointSet.end())) {
                if (isNpcSpawnable(characterSpawnPoint, spawnPoint, monsterMinDistance)) {
                    //spawnPointSet.insert(spawnPoint);
                    addSpawnTemplate(++regionIndex, spawnPoint, spawnTemplate);
                    ++spawnCount;
                    continue;
                }
            }
            ++missCount;
            if (missCount > (spawnTemplate.pool_ * 10)) {
                break;
            }
        }
    }

    for (const RegionSpawnTemplate& spawnTemplate : getTreasureSpawnTemplates(*spawns)) {
        for (int32_t spawnCount = 0, missCount = 0; spawnCount < spawnTemplate.pool_;) {
            const SpawnPoint spawnPoint = getRandomSpawnPoint();
            const TileType tileType = TileType(int(map_[spawnPoint.row_][spawnPoint.column_]));
            if (isTreasureSpawnable(tileType) && (spawnPointSet.find(spawnPoint) == spawnPointSet.end())) {
                addSpawnTemplate(++regionIndex, spawnPoint, spawnTemplate, rtTreasure);
                ++spawnCount;
                continue;
            }
            ++missCount;
            if (missCount > (spawnTemplate.pool_ * 10)) {
                break;
            }
        }
    }

    return true;
}


// TODO: 최적화
std::string RandomDungeonConstructor::compressMap()
{
    typedef sne::core::Vector<TileType> Tiles;
    typedef sne::core::Vector<int> Integers;

    Tiles tiles;
    Integers counts;
    Integers ocounts;
    Integers oris;

    int cval = -2;
    int co = -2;
    for (int y = 0; y < totalRows_; y++) {
        for (int x = 0; x < totalColumns_; x++) {
            const TileType t = TileType(int(map_[y][x]));
            const int orientation = int(roundf((map_[y][x] - t) * 10.0f));
            if (cval == t) {
                assert(! counts.empty());
                ++counts.back();
            }
            else {
                tiles.push_back(t);
                counts.push_back(1);
                cval = t;
            }
            if (co == orientation) {
                assert(! ocounts.empty());
                ++ocounts.back();
            }
            else {
                oris.push_back(orientation);
                ocounts.push_back(1);
                co = orientation;
            }
        }
    }

    std::string tilesResult;
    for (size_t c = 0; c < tiles.size(); ++c) {
        tilesResult += s_cc[tiles[c]];
    }

    std::string orisResult;
    size_t c = 0;
    const size_t orisSize = oris.size();
    while (c < orisSize) {
        int ov = oris[c];
        ++c;
        if (c < orisSize) {
            ov += (oris[c] * 4);
        }
        ++c;
        if (c < orisSize) {
            ov += (oris[c] * 16);
        }
        orisResult += s_cc[ov];
        ++c;
    }

    std::string countsResult;
    {
        for (size_t i = 0; i < counts.size(); ++i) {
            if (counts[i] >= 64) {
                countsResult += ":" + s_cc[counts[i] / 64] + s_cc[counts[i] % 64];
            }
            else {
                countsResult += s_cc[counts[i]];
            }
        }
    }

    std::string ocountsResult;
    {
        for (size_t i = 0; i < ocounts.size(); ++i) {
            if (ocounts[i] >= 64) {
                ocountsResult += ":" + s_cc[ocounts[i] / 64] + s_cc[ocounts[i] % 64];
            }
            else {
                ocountsResult += s_cc[ocounts[i]];
            }
        }
    }

    const std::string result = tilesResult + "+" + orisResult + "+" + countsResult + "+" + ocountsResult;
    //cocheck_[0] = result;

    // TODO: 연속되는 문자열 압축
    //for (int m = _countof(mults) - 1; m >= 0; --m) {
    //    for (size_t c = 0; c < _countof(cc); ++c) {
    //        eval("result = result.replace(/[" + cc[c] + "]{" + (m + 3) + "}/gm, '" + mults[m] + cc[c] + "');")
    //    }
    //}
    //cocheck_[1] = result;

    std::string compressed;
    const size_t resultSize = result.size();
    const size_t lastResultIndex = resultSize - 1;
    for (size_t r = 2; r < resultSize; ++r) {
        if ((! _isnan(result[r - 2])) && (! _isnan(result[r - 1])) && (! _isnan(result[r]))) {
            if (result[r - 2] < 4 && result[r - 1] < 4 && result[r] < 4) {
                const int newv = (result[r - 2] * 16) + (result[r - 1] * 4) + result[r];
                compressed += "^" + s_cc[newv];
                if (r < lastResultIndex) {
                    r += 2;
                }
            }
            else {
                compressed += result[r - 2];
                if (r == lastResultIndex) {
                    compressed += result[r - 1] + result[r];
                }
            }
        }
        else {
            compressed += result[r - 2];
            if (r == lastResultIndex) {
                compressed += result[r - 1] + result[r];
            }
        }
    }
    //cocheck_[2] = compressed;
    return compressed;
}


void RandomDungeonConstructor::uncompressMap(const std::string& deText)
{
    std::string rawText;
    rawText.reserve(deText.size() * 3);
    for (size_t i = 0; i < deText.size();) {
        if (deText[i] == '^') {
            const size_t b = s_cc.find_first_of(deText[i + 1]);
            assert(b != std::string::npos);
            rawText.push_back(s_cc[(b >> 4) & 3]);
            rawText.push_back(s_cc[(b >> 2) & 3]);
            rawText.push_back(s_cc[b & 3]);
            ++i;
        } else {
            rawText.push_back(deText[i]);
        }
        ++i;
    }
    //cocheck_[3] = rawText;

    // TODO: 반복 문자열 압축 해제
    //for (size_t p = 0; p < rawText.size() - 1; ++p) {
    //    const size_t k = mults.find_first_of(rawText[p]);
    //    if (k != std::string::npos) {
    //        rawText.erase(p);
    //        rawText.insert(p, chrMuliply(rawText[p], (k - 1) + 3));
    //    }
    //}

    const Strings plusSperated = split(rawText, '+');
    //cocheck_[4] = rawText;

    //a = a.join("").split("+");
    //cocheck_[4] = a.join("+");

    std::string g;

    // g = plusSperated[3];
    //std::string o;
    //o.reserve(g.size());
    //for (size_t p = 0; p < g.size(); ++p) {
    //    if (g[p] == ':') {
    //        o.push_back(char(cc.find_first_of(g[p + 1]) * 64 + cc.find_first_of(g[p + 2])));
    //        p += 2;
    //    } else {
    //        o.push_back(char(cc.find_first_of(g[p])));
    //    }
    //}

    g = plusSperated[2];
    sne::core::Vector<int> r;
    r.reserve(g.size());
    for (size_t p = 0; p < g.size(); ++p) {
        if (g[p] == ':') {
            r.push_back(int(s_cc.find_first_of(g[p + 1]) * 64) + int(s_cc.find_first_of(g[p + 2])));
            p += 2;
        } else {
            r.push_back(int(s_cc.find_first_of(g[p])));
        }
    }

    //g = plusSperated[1];
    //std::string s;
    //s.reserve(g.size());
    //for (size_t p = 0; p < g.size(); ++p) {
    //    s.push_back(char(cc.find_first_of(g[p]) & 3));
    //    s.push_back(char(cc.find_first_of(g[p]) & 12 / 4));
    //    s.push_back(char(cc.find_first_of(g[p]) & 48 / 16));
    //}

    g = plusSperated[0];
    std::string q;
    q.reserve(g.size());
    for (size_t p = 0; p < g.size(); ++p) {
        q.push_back(char(s_cc.find_first_of(g[p])));
    }

    int h = -1;
    int d = 0;
    for (int row = 0; row < totalRows_; ++row) {
        for (int col = 0; col < totalColumns_; ++col) {
            if (d == 0) {
                ++h;
                d = r[h];
            }
            map_[row][col] = q[h];
            --d;
        }
    }

    //$("div#encoded").html("1c:" + cocheck_[1] + "<br />1u:" + cocheck_[3] + "<br />");
    //$("div#encoded").html($("div#encoded").html() + "<br />2c:" + cocheck_[0] + "<br />2u:" + cocheck_[4] + "<br />");
    //return map.slice()
}


void RandomDungeonConstructor::initMap()
{
    map_.resize(totalRows_);
    for (uint16_t row = 0; row < totalRows_; ++row) {
        map_[row].resize(totalColumns_);
        for (uint16_t column = 0; column < totalColumns_; ++column) {
            map_[row][column] = TFREE;
        }
    }

    // TODO: saveLevel();
}


void RandomDungeonConstructor::refreshMap()
{
    for (uint16_t row = 0; row < totalRows_; ++row) {
        for (uint16_t column = 0; column < totalColumns_; ++column) {
            if (map_[row][column] != TFREE) {
                refreshPosition(column, row);
            }
        }
    }
}


void RandomDungeonConstructor::refreshPosition(uint16_t column, uint16_t row)
{
    const float tileType = map_[row][column];
    if (tileType == TFREE) {
        return;
    }

    TileType tileId = TUNKNOWN;
    int orientation = 0;
    const float tileInfo = autoTileInfo(column, row);
    if (! isVariationOf(uint16_t(tileType), uint16_t(tileInfo))) {
        tileId = TileType(int(tileInfo));
        orientation = int(roundf((tileInfo - tileId) * 10.0f));
    }
    else {
        tileId = TileType(int(tileType));
        orientation = int(roundf((tileType - tileId) * 10.0f));
    }

    if (orientation > 3) {
        orientation = 0;
    }

    if ((tileId == TFLOOR) || (tileId == TCOLUMN) || (tileId == TCORRIDORX) || (tileId == TUNKNOWN)) {
        orientation = 0;
    }
    else if ((tileId == TCORRIDORSML) || (tileId == TCORRIDOR)) {
        if (orientation > 1) {
            orientation = orientation - 2;
        }
    }
    else if (tileId == TFREE) {
        orientation = 0;
    }

    // 소수점 이하는 방향을 10으로 나눈 값으로 설정한다
    map_[row][column] = tileId + (orientation / 10.0f);
}


float RandomDungeonConstructor::autoTileInfo(uint16_t column, uint16_t row)
{
    Neighbors neighbors;
    neighbors.fill(TFREE);

    for (int r = row - 1; r <= row + 1; ++r) {
        for (int c = column - 1; c <= column + 1; ++c) {
            if ((c != column) || (r != row)) {
                const int i = c - column + 1;
                const int h = r - row + 1;
                int d = h * 3 + i;
                if (d >= 5) {
                    --d;
                }
                neighbors[d] = TINVALID;
                if (c < 0) {
                    neighbors[d] = TFREE;
                }
                if (c > totalColumns_ - 1) {
                    neighbors[d] = TFREE;
                }
                if (r < 0) {
                    neighbors[d] = TFREE;
                }
                if (r > totalRows_ - 1) {
                    neighbors[d] = TFREE;
                }
                if (neighbors[d] == TINVALID) {
                    neighbors[d] = TileType(int(map_[r][c]));
                }
            }
        }
    }

    const size_t tileCount = mainTileCount(neighbors);
    if (tileCount == 0) {
        return TUNKNOWN;
    }

    if (tileCount == 1) {
        return checkCorridorEnd(neighbors);
    }
    switch (tileCount + subTileCount(neighbors)) {
    case 2:
        switch (subTileCount(neighbors)) {
        case 0:
            if (neighbors[TPNorth] != TFREE && neighbors[TPSouth] != TFREE) {
                return TCORRIDOR + ONORTH;
            } else {
                if (neighbors[TPWest] != TFREE && neighbors[TPEast] != TFREE) {
                    return TCORRIDOR + OWEST;
                } else {
                    return checkCorridorCorner(neighbors);
                }
            }
        }
    case 3:
        switch (subTileCount(neighbors)) {
        case 0:
            return checkTJunction(neighbors);
        case 1:
            return check2_1(neighbors);
        }
    case 4:
        switch (subTileCount(neighbors)) {
        case 0:
            return TCORRIDORX;
        case 1:
            return checkTJunction(neighbors);
        case 2:
            return check2_1(neighbors);
        }
    case 5:
        switch (subTileCount(neighbors)) {
        case 1:
            return TFLOOR;
        case 2:
            return checkTJunction(neighbors);
        case 3:
            return check2_1(neighbors);
        }
    case 6:
        switch (subTileCount(neighbors)) {
        case 2:
            return TFLOOR;
        case 3:
            return checkTJunction(neighbors);
        case 4:
            return check2_1(neighbors);
        }
    case 7:
        switch (subTileCount(neighbors)) {
        case 3:
            return TFLOOR;
        case 4:
            return checkTJunction(neighbors);
        }
    case 8:
        return TFLOOR;
    }
    return TUNKNOWN;
}


bool RandomDungeonConstructor::isVariationOf(uint16_t tileType, uint16_t  tileInfo) const
{
    for (int a = 0; a < TileInfo::tileCount; ++a) {
        if (tileData_[tileType].tileType_[a] == tileInfo) {
            return true;
        }
    }
    return false;
}


size_t RandomDungeonConstructor::mainTileCount(const Neighbors& neighbors) const
{
    size_t count = 0;
    if (neighbors[TPNorth] > TFREE) {
        ++count;
    }
    if (neighbors[TPEast] > TFREE) {
        ++count;
    }
    if (neighbors[TPSouth] > TFREE) {
        ++count;
    }
    if (neighbors[TPWest] > TFREE) {
        ++count;
    }
    return count;
}


size_t RandomDungeonConstructor::subTileCount(const Neighbors& neighbors) const
{
    size_t count = 0;
    if (neighbors[TPNorthEast] > TFREE) {
        ++count;
    }
    if (neighbors[TPNorthWest] > TFREE) {
        ++count;
    }
    if (neighbors[TPSouthEast] > TFREE) {
        ++count;
    }
    if (neighbors[TPSouthWest] > TFREE) {
        ++count;
    }
    return count;
}


float RandomDungeonConstructor::checkCorridorEnd(const Neighbors& neighbors) const
{
    if (neighbors[TPNorth] != TFREE &&
        (neighbors[TPNorthEast] != TFREE || neighbors[TPNorthWest] != TFREE)) {
        return TCORRIDOREND + ONORTH;
    }
    if (neighbors[TPEast] != TFREE &&
        (neighbors[TPNorthEast] != TFREE || neighbors[TPSouthEast] != TFREE)) {
        return TCORRIDOREND + OEAST;
    }
    if (neighbors[TPSouth] != TFREE &&
        (neighbors[TPSouthEast] != TFREE || neighbors[TPSouthWest] != TFREE)) {
        return TCORRIDOREND + OSOUTH;
    }
    if (neighbors[TPWest] != TFREE &&
        (neighbors[TPNorthWest] != TFREE || neighbors[TPSouthWest] != TFREE)) {
        return TCORRIDOREND + OWEST;
    }
    if (neighbors[TPNorth] != TFREE) {
        return TCORRIDOREND + ONORTH;
    }
    if (neighbors[TPEast] != TFREE) {
        return TCORRIDOREND + OEAST;
    }
    if (neighbors[TPSouth] != TFREE) {
        return TCORRIDOREND + OSOUTH;
    }
    if (neighbors[TPWest] != TFREE) {
        return TCORRIDOREND + OWEST;
    }
    return 0.0f;
}


float RandomDungeonConstructor::checkCorridorCorner(const Neighbors& neighbors) const
{
    if (neighbors[TPNorth] == TFREE && neighbors[TPEast] == TFREE) {
        return TCORRIDORCORNER + ONORTH;
    }
    if (neighbors[TPEast] == TFREE && neighbors[TPSouth] == TFREE) {
        return TCORRIDORCORNER + OEAST;
    }
    if (neighbors[TPSouth] == TFREE && neighbors[TPWest] == TFREE) {
        return TCORRIDORCORNER + OSOUTH;
    }
    if (neighbors[TPWest] == TFREE && neighbors[TPNorth] == TFREE) {
        return TCORRIDORCORNER + OWEST;
    }
    return 0.0f;
}


float RandomDungeonConstructor::checkTJunction(const Neighbors& neighbors) const
{
    if (subTileCount(neighbors) >= 1) {
        if (neighbors[TPWest] == TFREE &&
            (neighbors[TPNorthEast] != TFREE || neighbors[TPSouthEast] != TFREE)) {
            return TWALL + OWEST;
        }
        if (neighbors[TPNorth] == TFREE &&
            (neighbors[TPSouthEast] != TFREE || neighbors[TPSouthWest] != TFREE)) {
            return TWALL + ONORTH;
        }
        if (neighbors[TPEast] == TFREE &&
            (neighbors[TPNorthWest] != TFREE || neighbors[TPSouthWest] != TFREE)) {
            return TWALL + OEAST;
        }
        if (neighbors[TPSouth] == TFREE &&
            (neighbors[TPNorthEast] != TFREE || neighbors[TPNorthWest] != TFREE)) {
            return TWALL + OSOUTH;
        }
    }
    if (neighbors[TPNorth] == TFREE) {
        return TCORRIDORT + ONORTH;
    }
    if (neighbors[TPEast] == TFREE) {
        return TCORRIDORT + OEAST;
    }
    if (neighbors[TPSouth] == TFREE) {
        return TCORRIDORT + OSOUTH;
    }
    if (neighbors[TPWest] == TFREE) {
        return TCORRIDORT + OWEST;
    }
    return 0.0f;
}


float RandomDungeonConstructor::check2_1(const Neighbors& neighbors) const
{
    if (neighbors[TPNorth] != TFREE &&
        neighbors[TPWest] != TFREE && neighbors[TPNorthWest] != TFREE) {
        return TCORNER + OEAST;
    }
    if (neighbors[TPNorth] != TFREE &&
        neighbors[TPEast] != TFREE && neighbors[TPNorthEast] != TFREE) {
        return TCORNER + OSOUTH;
    }
    if (neighbors[TPSouth] != TFREE &&
        neighbors[TPEast] != TFREE && neighbors[TPSouthEast] != TFREE) {
        return TCORNER + OWEST;
    }
    if (neighbors[TPSouth] != TFREE &&
        neighbors[TPWest] != TFREE && neighbors[TPSouthWest] != TFREE) {
        return TCORNER + ONORTH;
    }
    if (neighbors[TPNorth] != TFREE &&
        neighbors[TPWest] != TFREE && neighbors[TPNorthWest] == TFREE) {
        return TCORRIDORCORNER + OEAST;
    }
    if (neighbors[TPNorth] != TFREE &&
        neighbors[TPEast] != TFREE && neighbors[TPNorthEast] == TFREE) {
        return TCORRIDORCORNER + OSOUTH;
    }
    if (neighbors[TPSouth] != TFREE &&
        neighbors[TPEast] != TFREE && neighbors[TPSouthEast] == TFREE) {
        return TCORRIDORCORNER + OWEST;
    }
    if (neighbors[TPSouth] != TFREE &&
        neighbors[TPWest] != TFREE && neighbors[TPSouthWest] == TFREE) {
        return TCORRIDORCORNER + ONORTH;
    }
    if (allCorridors(neighbors)) {
        if (neighbors[TPWest] != TFREE && neighbors[TPEast] != TFREE) {
            return TCORRIDOR + OWEST;
        }
        if (neighbors[TPNorth] != TFREE && neighbors[TPSouth] != TFREE) {
            return TCORRIDOR + ONORTH;
        }
    } else {
        if (neighbors[TPWest] != TFREE && neighbors[TPEast] != TFREE) {
            if (neighbors[TPNorthWest] != TFREE && neighbors[TPSouthWest] != TFREE) {
                return TCORRIDOR + OWEST;
            }
            if (neighbors[TPNorthEast] != TFREE && neighbors[TPSouthEast] != TFREE) {
                return TCORRIDOR + OEAST;
            }
            if (neighbors[TPNorthWest] != TFREE || neighbors[TPSouthWest] != TFREE) {
                return TCORRIDOR + OWEST;
            }
            if (neighbors[TPNorthEast] != TFREE || neighbors[TPSouthEast] != TFREE) {
                return TCORRIDOR + OEAST;
            }
        } else {
            if (neighbors[TPNorth] != TFREE && neighbors[TPSouth] != TFREE) {
                if (neighbors[TPNorthWest] != TFREE && neighbors[TPNorthEast] != TFREE) {
                    return TCORRIDOR + ONORTH;
                }
                if (neighbors[TPSouthWest] != TFREE && neighbors[TPSouthEast] != TFREE) {
                    return TCORRIDOR + OSOUTH;
                }
                if (neighbors[TPNorthWest] != TFREE || neighbors[TPNorthEast] != TFREE) {
                    return TCORRIDOR + ONORTH;
                }
                if (neighbors[TPSouthWest] != TFREE || neighbors[TPSouthEast] != TFREE) {
                    return TCORRIDOR + OSOUTH;
                }
            }
        }
    }
    return 0.0f;
}


float RandomDungeonConstructor::allCorridors(const Neighbors& neighbors) const
{
    if (neighbors[TPWest] < TCORRIDORSML && neighbors[TPWest] > TFREE) {
        return false;
    }
    if (neighbors[TPNorth] < TCORRIDORSML && neighbors[TPNorth] > TFREE) {
        return false;
    }
    if (neighbors[TPEast] < TCORRIDORSML && neighbors[TPEast] > TFREE) {
        return false;
    }
    if (neighbors[TPSouth] < TCORRIDORSML && neighbors[TPSouth] > TFREE) {
        return false;
    }
    if (neighbors[TPNorthWest] < TCORRIDORSML && neighbors[TPNorthWest] > TFREE) {
        return false;
    }
    if (neighbors[TPNorthEast] < TCORRIDORSML && neighbors[TPNorthEast] > TFREE) {
        return false;
    }
    if (neighbors[TPSouthEast] < TCORRIDORSML && neighbors[TPSouthEast] > TFREE) {
        return false;
    }
    if (neighbors[TPSouthWest] < TCORRIDORSML && neighbors[TPSouthWest] > TFREE) {
        return false;
    }
    return true;
}


void RandomDungeonConstructor::addSpawnTemplate(uint16_t regionIndex,
    const SpawnPoint& spawnPoint, const RegionSpawnTemplate& baseSpawnTemplate,
    RegionType regionType)
{
    const RegionCode regionCode = makeRegionCode(regionType, regionIndex + 1);
    const Position spawnPosition =
        getPosition(spawnPoint.row_, spawnPoint.column_, spawnPoint.level_);

    static_cast<RandomDungeonRegionTable&>(*regionTable_).addRegion(regionCode);
    static_cast<RandomDungeonRegionCoordinates&>(*regionCoordinates_).
        addCoordinates(regionCode, spawnPosition);

    static_cast<RandomDungeonNpcSpawnTable&>(*spawnTable_).
        addSpawn(regionCode, baseSpawnTemplate);
}


RandomDungeonConstructor::SpawnPoint RandomDungeonConstructor::getCharacterSpawnPoint() const
{
    for (int16_t row = 0; row < totalRows_; ++row) {
        for (int16_t column = 0; column < totalColumns_; ++column) {
            const TileType tileType = TileType(int(map_[row][column]));
            if (isCharacterSpawnable(tileType)) {
                return SpawnPoint(actLevel_, row, column);
            }
        }
    }
    return SpawnPoint();
}


RandomDungeonConstructor::SpawnPoint RandomDungeonConstructor::getRandomSpawnPoint() const
{
    const int16_t row = esut::random() % totalRows_;
    const int16_t column = esut::random() % totalColumns_;
    return SpawnPoint(actLevel_, row, column);
}


Position RandomDungeonConstructor::getPosition(int row, int column, int level) const
{
    return Position(xOffset_ + (((totalColumns_ - 1) - column) * xTileSize * mapScale),
        yOffset_ + (row * yTileSize * mapScale),
        zOffset_ + (level * zTileSize * mapScale));
}

}} // namespace gideon { namespace randun {
