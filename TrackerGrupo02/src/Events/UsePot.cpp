#include "UsePot.h"

std::string UsePot::toJson()
{
	TrackerEvent::commonJson();
	return mainJson.to_string();
}

UsePot::UsePot() :TrackerEvent() {}

