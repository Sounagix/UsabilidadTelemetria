#include "Logout.h"
#include "jute.h"

std::string Logout::toJson()
{
	TrackerEvent::commonJson();
	return mainJson.to_string();
}

Logout::Logout() : TrackerEvent() {}
