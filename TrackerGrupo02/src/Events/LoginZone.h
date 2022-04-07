#pragma once
#include "TrackerEvent.h"

class LoginZone : public TrackerEvent
{
private:
	int zone;
	bool completed;
public:
	void toJson();
	LoginZone(int time, string idu, string idg,int z, bool comp);
};

