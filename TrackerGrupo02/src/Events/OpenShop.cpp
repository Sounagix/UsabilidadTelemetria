#include "OpenShop.h"

std::string OpenShop::toJson()
{
	TrackerEvent::commonJson();
	return mainJson.to_string();
}

OpenShop::OpenShop() :TrackerEvent() {}
