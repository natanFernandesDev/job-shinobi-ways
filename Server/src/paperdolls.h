// Copyright 2022 The Forgotten Server Authors. All rights reserved.
// Use of this source code is governed by the GPL-2.0 License that can be found in the LICENSE file.

#include "player.h"

struct Paperdoll {
	Paperdoll(uint16_t id, uint16_t itemId, uint16_t lookType) : id(id), itemId(itemId), lookType(lookType) {}

	uint16_t id;
	uint16_t itemId;
	uint16_t lookType;

	std::vector<uint16_t> lookTypes;
};

class Paperdolls
{
	public:
		static Paperdolls& getInstance() {
			static Paperdolls instance;
			return instance;
		}

		bool loadFromXml();

		Paperdoll* getPaperdollByItemId(uint16_t itemId);

	private:
		std::vector<Paperdoll> paperdolls;
};
