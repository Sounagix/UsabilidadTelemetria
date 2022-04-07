#pragma once
#include "TrackerEvent.h"

class LogoutZone : public TrackerEvent
{
private:
	int zone;
	bool completed;
public:
	void toJson();
	LogoutZone(int time, string idu, string idg, int z, bool comp);
};

