#pragma once
#include "TrackerEvent.h"

class OpenShop : public TrackerEvent
{
public:
	std::string toJson();
	OpenShop();
};

