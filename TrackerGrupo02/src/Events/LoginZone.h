#pragma once
#include "TrackerEvent.h"

class LoginZone : public TrackerEvent
{
private:
	int zone;
	bool completed;
public:
	void toJson();
	LoginZone(int timeStamp, std::string idUser, std::string idGame,int z, bool comp);
};

