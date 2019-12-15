#pragma once

namespace gideon {

/**
 * @struct CharacterAppearance
 * Charcter 외형 정보
 */
struct CharacterAppearance
{
	uint8_t hair_;
	uint8_t face_;
	uint8_t eyes_;

	explicit CharacterAppearance(uint8_t hair = 0,
		uint8_t face = 0, uint8_t eyes = 0) :
		hair_(hair),
		face_(face),
		eyes_(eyes)
	{
    }

    void reset() {
		hair_ = 0;
		face_ = 0;
		eyes_ = 0;
	}

    bool isValid() const {
        return hair_ > 0 && face_ > 0 && eyes_ > 0;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & hair_ & face_ & eyes_;
    }
};

} // namespace gideon {
