#include "OpenChest.h"

std::string OpenChest::toJson()
{
	TrackerEvent::commonJson();

	jute::jValue num(jute::jType::JBOOLEAN);
	num.set_string(std::to_string((bool)_openInv));
	mainJson.add_property("openInv", num);

	return mainJson.to_string();
}

void OpenChest::setOpenInv(bool openInv)
{
	_openInv = openInv;
}

bool OpenChest::getOpenInv()
{
	return _openInv;
}

OpenChest::OpenChest() :TrackerEvent() {}
