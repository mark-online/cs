#pragma once

#include <gideon/cs/datatable/ExpTable.h>
#include <gideon/cs/datatable/template/exp_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class ExpTable
 *
 */
class ExpTableImpl : public ExpTable
{
public:
    ExpTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            std::unique_ptr<gdt::exp_table> expTable =
                gdt::exp_table_(is, ::xml_schema::flags::dont_validate);

            LevelStepExpPoints invalidLevelStepExpPoints;
            invalidLevelStepExpPoints.fill(ceMin);
            expPoints_[clInvalidLevel] = invalidLevelStepExpPoints;
            int i = clMinLevel;
            for (const gdt::exp_t& exp : expTable->exp_template()) {
                if (clMaxPlayerLevel < i) {
                    continue;
                }
                LevelStepExpPoints& points = expPoints_[i];
                points[0] = static_cast<ExpPoint>(exp.minor_level_exp_0());
                points[1] = static_cast<ExpPoint>(exp.minor_level_exp_1());
                points[2] = static_cast<ExpPoint>(exp.minor_level_exp_2());
                points[3] = static_cast<ExpPoint>(exp.minor_level_exp_3());
                points[4] = static_cast<ExpPoint>(exp.minor_level_exp_4());
                ++i;
            }
            assert(i == clMaxPlayerCount);
            isLoaded_ = true;

            ExpTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual ExpPoint getExpPoint(CreatureLevel cl, LevelStep ls) const {
        assert(isValidPlayerLevel(cl) && isValid(ls));
        return expPoints_[cl][ls];
    }

    virtual const ExpPoints& getExpPoints() const {
        return expPoints_;
    }
    
    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    ExpPoints expPoints_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
