#include "OpenChest.h"

std::string OpenChest::toJson()
{
	TrackerEvent::commonJson();
	return mainJson.to_string();
}

OpenChest::OpenChest() :TrackerEvent() {}
