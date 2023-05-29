// Copyright 2022 The Forgotten Server Authors. All rights reserved.
// Use of this source code is governed by the GPL-2.0 License that can be found in the LICENSE file.

#include "player.h"

struct Paperdoll {
	Paperdoll(uint16_t id, uint16_t itemId, uint16_t lookType) : id(id), itemId(itemId), lookType(lookType) {}

	uint16_t id;
	uint16_t itemId;
	uint16_t lookType;

	std::vector<uint16_t> lookTypes;

	bool baseExists(uint16_t looktype) const {
		return std::find(lookTypes.begin(), lookTypes.end(), looktype) != lookTypes.end();
	}

};

class Paperdolls
{
	public:
		static Paperdolls& getInstance() {
			static Paperdolls instance;
			return instance;
		}

		bool loadFromXml();

		Paperdoll* getPaperdollByItemId(PlayerSex_t sex, uint16_t itemId);

		bool isValidSlot(uint8_t index);

	private:
		std::vector<Paperdoll> paperdolls[PLAYERSEX_LAST + 1];
};
