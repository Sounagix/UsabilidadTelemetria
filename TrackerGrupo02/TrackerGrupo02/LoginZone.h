#pragma once
#include "../src/TrackerEvent.h"

class LoginZone : public TrackerEvent
{
public:
	void toJson();
	LoginZone(int time, string idu, string idg);
};

