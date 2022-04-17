#pragma once
#include "TrackerEvent.h"

class OpenChest : public TrackerEvent
{
public:
	std::string toJson();
	OpenChest();
};

