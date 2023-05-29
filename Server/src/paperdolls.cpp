// Copyright 2022 The Forgotten Server Authors. All rights reserved.
// Use of this source code is governed by the GPL-2.0 License that can be found in the LICENSE file.

#include "otpch.h"
#include "pugicast.h"
#include "paperdolls.h"

bool Paperdolls::loadFromXml()
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("data/XML/paperdolls.xml");
	if (!result) {
		printXMLError("Error - Paperdolls::loadFromXml", "data/XML/paperdolls.xml", result);
		return false;
	}

	uint16_t id = 0;
	for (auto paperdollNode : doc.child("paperdolls").children()) {
		pugi::xml_attribute attr;
		if ((attr = paperdollNode.attribute("enabled")) && !attr.as_bool()) {
			continue;
		}

		if (!(attr = paperdollNode.attribute("type"))) {
			std::cout << "[Warning - Paperdolls::loadFromXml] Missing paperdoll type." << std::endl;
			continue;
		}

		uint16_t type = pugi::cast<uint16_t>(attr.value());
		if (type > PLAYERSEX_LAST) {
			std::cout << "[Warning - Paperdolls::loadFromXml] Invalid paperdoll type " << type << "." << std::endl;
			continue;
		}

		paperdolls[type].emplace_back(
			++id,
			pugi::cast<uint32_t>(paperdollNode.attribute("itemid").value()),
			pugi::cast<uint16_t>(paperdollNode.attribute("looktype").value())
		);
		Paperdoll& paperdoll = paperdolls[type].back();

		for (auto baseNode : paperdollNode.children()) {
			uint16_t looktype = pugi::cast<uint16_t>(baseNode.attribute("looktype").value());
			paperdoll.lookTypes.emplace_back(looktype);
		}
	}

	return true;
}

Paperdoll* Paperdolls::getPaperdollByItemId(PlayerSex_t sex, uint16_t itemId)
{
	for (Paperdoll& paperdoll : paperdolls[sex]) {
		if (paperdoll.itemId == itemId) {
			return &paperdoll;
		}
	}
	return nullptr;

}

bool Paperdolls::isValidSlot(uint8_t index) {
	return (index == CONST_SLOT_HEAD ||
		index == CONST_SLOT_ARMOR ||
		index == CONST_SLOT_LEGS ||
		index == CONST_SLOT_FEET);
}
