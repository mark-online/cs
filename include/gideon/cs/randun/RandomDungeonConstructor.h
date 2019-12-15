#pragma once

#include <gideon/cs/datatable/SpawnTemplate.h>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <gideon/cs/shared/data/MonsterInfo.h>
#include <sne/core/container/Containers.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {
class RegionTable;
class RegionCoordinates;
class RegionSpawnTable;
class NpcTable;
}} // namespace gideon { namespace datatable {

namespace gideon { namespace randun {

/**
 * @struct ExportParameters
 */
struct ExportParameters
{
    std::string missionTemplate_;
    std::string baseFolder_;
    uint8_t floorCount_;
    uint8_t wallCount_;
    uint8_t cornerCount_;
    uint8_t corridorCount_;
    uint8_t corridorCornerCount_;
    uint8_t corridorCrossCount_;
    uint8_t corridorTCrossCount_;
    uint8_t corridorEndCount_;

    ExportParameters(const std::string& missionTemplate, const std::string& baseFolder) :
        missionTemplate_(missionTemplate),
        baseFolder_(baseFolder),
        floorCount_(1),
        wallCount_(1),
        cornerCount_(1),
        corridorCount_(1),
        corridorCornerCount_(1),
        corridorCrossCount_(1),
        corridorTCrossCount_(1),
        corridorEndCount_(1) {}
};


/**
 * @class RandomDungeonConstructor
 * 랜덤 던전 생성기
 */
class GIDEON_CS_API RandomDungeonConstructor : public boost::noncopyable
{
public:
    enum TileType {
        TINVALID = -1,
        TFREE = 0,
        TTAKEN = 1,
        TFLOOR = 2,
        TWALL = 3,
        TCORNER = 4,
        TDOOR = 5,
        TTORCH = 6,
        TBAY = 7,
        TCOLUMN = 8,
        TCOLUMNBR = 9,
        TCOLUMNINF = 10,
        TCORRIDORSML = 11,
        TCORRIDORXSML = 12,
        TCORRIDOR = 13,
        TCORRIDORX = 14,
        TCORRIDORCORNER = 15,
        TCORRIDOREND = 16,
        TCORRIDORT = 17,
        TCORRIDORDOOR = 18,
        TUNKNOWN = 31,

        TCOUNT,
        TPOINTER = 99,
    };

    enum TilePosition {
        TPNorthWest = 0,
        TPNorth = 1,
        TPNorthEast = 2,
        TPWest = 3,
        TPEast = 4,
        TPSouthWest = 5,
        TPSouth = 6,
        TPSouthEast = 7,

        TPCount
    };

    enum Config {
        defaultColumns = 32, //64
        defaultRows = 16 //32
    };

    struct SpawnPoint {
        int16_t row_;
        int16_t column_;
        int16_t level_;

        explicit SpawnPoint(int16_t level = 0, int16_t row = -1, int16_t column = -1) :
            row_(row),
            column_(column),
            level_(level) {}

        bool isValid() const {
            return (row_ != -1) && (column_ != -1) && (level_ != -1);
        }

        bool operator<(const SpawnPoint& rhs) const {
            if (level_ < rhs.level_) {
                return true;
            }
            else if (level_ > rhs.level_) {
                return false;
            }
            if (row_ < rhs.row_) {
                return true;
            }
            else if (row_ > rhs.row_) {
                return false;
            }
            return column_ < rhs.column_;
        }
    };

    struct TileInfo {
        enum { tileCount = 3 };

        std::string name_;
        int16_t degrees_;
        TileType tileType_[tileCount];

        explicit TileInfo(const std::string& name = "", int16_t degrees = 0,
            TileType tileType1 = TUNKNOWN, TileType tileType2 = TUNKNOWN,
            TileType tileType3 = TUNKNOWN) :
            name_(name),
            degrees_(degrees) {
            tileType_[0] = tileType1;
            tileType_[1] = tileType2;
            tileType_[2] = tileType3;
        }
    };

    typedef std::array<TileInfo, TCOUNT> TileTypes;

    typedef sne::core::Vector<float> Columns;
    typedef sne::core::Vector<Columns> Map;

    typedef std::array<TileType, TPCount> Neighbors;

    typedef sne::core::Vector<RegionSpawnTemplate> SpawnTemplates;

public:
    RandomDungeonConstructor(uint16_t columns = defaultColumns, uint16_t rows = defaultRows,
        uint16_t baseZ = 10);
    ~RandomDungeonConstructor();

    /// random dungeon을 생성한다
    void generate(uint16_t genLength, uint16_t genSteps);

    /// DE 포맷을 import한다
    void importDe(const std::string& de);

    /// DE 포맷으로 export한다
    std::string exportDe();

    /// Mission 포맷으로 export한다
    std::string exportMission(const ExportParameters& params);

    /// 맵을 분석하여 테이블을 만든다
    bool analyze(const datatable::RegionSpawnTable* baseSpawnTable,
        const datatable::NpcTable* npcTable);

public:
    MapInfo getMapInfo(MapCode mapCode, uint16_t sectorLength) const;

    const datatable::RegionTable* getRegionTable() const {
        return regionTable_.get();
    }

    const datatable::RegionCoordinates* getRegionCoordinates() const {
        return regionCoordinates_.get();
    }

    const datatable::RegionSpawnTable* getSpawnTable() const {
        return spawnTable_.get();
    }

private:
    void initMap();
    void refreshMap();
    void refreshPosition(uint16_t a, uint16_t c);
    float autoTileInfo(uint16_t column, uint16_t row);

    std::string compressMap();
    void uncompressMap(const std::string& deText);

private:
    bool isVariationOf(uint16_t tileType, uint16_t  tileInfo) const;

    size_t mainTileCount(const Neighbors& neighbors) const;
    size_t subTileCount(const Neighbors& neighbors) const;
    float checkCorridorEnd(const Neighbors& neighbors) const;
    float checkCorridorCorner(const Neighbors& neighbors) const;
    float checkTJunction(const Neighbors& neighbors) const;
    float check2_1(const Neighbors& neighbors) const;
    float allCorridors(const Neighbors& neighbors) const;

private:
    void addSpawnTemplate(uint16_t regionIndex, const SpawnPoint& spawnPoint,
        const RegionSpawnTemplate& baseSpawnTemplate, RegionType regionType = rtNpcSpawn);

    SpawnPoint getCharacterSpawnPoint() const;
    SpawnPoint getRandomSpawnPoint() const;

    Position getPosition(int row, int column, int level) const;

private:
    static inline bool isCharacterSpawnable(TileType tileType) {
        return (tileType == TCORRIDORCORNER) || (tileType == TCORNER) ||
            (tileType == TCORRIDOREND);
    }

    static inline bool isNpcSpawnable(TileType tileType) {
        return (tileType != TCOLUMN) && (tileType != TCOLUMNBR) &&
            (tileType != TCOLUMNINF) && (tileType != TFREE);
    }

    static inline bool isTreasureSpawnable(TileType tileType) {
        return (tileType != TCOLUMN) && (tileType != TCOLUMNBR) &&
            (tileType != TCOLUMNINF) && (tileType != TFREE);
    }

    static inline bool isNpcSpawnable(
        const SpawnPoint& characterSpawnPoint, const SpawnPoint& npcSpawnPoint, int minDistance) {
        const int xDistance = abs(characterSpawnPoint.column_ - npcSpawnPoint.column_);
        if (xDistance < minDistance) {
            return false;
        }
        const int yDistance = abs(characterSpawnPoint.row_ - npcSpawnPoint.row_);
        if (yDistance < minDistance) {
            return false;
        }
        return true;
    }

private:
    const uint16_t totalColumns_;
    const uint16_t totalRows_;

    float xOffset_;
    float yOffset_;
    float zOffset_;

    TileTypes tileData_;
    Map map_;

    TileType actBrush_;
    uint8_t actLevel_;

    //std::array<std::string, 5> cocheck_;

    std::unique_ptr<datatable::RegionTable> regionTable_;
    std::unique_ptr<datatable::RegionCoordinates> regionCoordinates_;
    std::unique_ptr<datatable::RegionSpawnTable> spawnTable_;
};

}} // namespace gideon { namespace randun {
