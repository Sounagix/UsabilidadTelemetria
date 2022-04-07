#pragma once
#include "TrackerEvent.h"

class Logout : public TrackerEvent
{
public:
	void toJson();
	Logout(int time, string idu, string idg);
};

