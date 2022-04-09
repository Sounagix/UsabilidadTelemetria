#pragma once
#include "TrackerEvent.h"

class Logout : public TrackerEvent
{
public:
	std::string toJson();
	Logout();
};

