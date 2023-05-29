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
		uint32_t itemId = pugi::cast<uint32_t>(paperdollNode.attribute("itemid").value());

		if (getPaperdollByItemId(itemId)) {
			std::cout << "[Notice - Paperdolls::loadFromXml] Duplicate paperdoll with itemid: " << itemId << std::endl;
			continue;
		}

		paperdolls.emplace_back(
			++id,
			itemId,
			pugi::cast<uint16_t>(paperdollNode.attribute("looktype").value())
		);
		Paperdoll& paperdoll = paperdolls.back();

		for (auto baseNode : paperdollNode.children()) {
			uint16_t looktype = pugi::cast<uint16_t>(baseNode.attribute("looktype").value());
			paperdoll.lookTypes.emplace_back(looktype);
		}
	}

	return true;
}

Paperdoll* Paperdolls::getPaperdollByItemId(uint16_t itemId)
{
	auto it = std::find_if(paperdolls.begin(), paperdolls.end(), [itemId](const Paperdoll& paperdoll) {
		return paperdoll.itemId == itemId;
	});

	return it != paperdolls.end() ? &*it : nullptr;
}
