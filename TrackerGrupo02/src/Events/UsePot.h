#pragma once
#include "TrackerEvent.h"

class UsePot : public TrackerEvent
{
public:
	std::string toJson();
	UsePot();
};

