#pragma once
#include "TrackerEvent.h"

class LogoutZone : public TrackerEvent
{
private:
	int _zone;
	int _next;
public:
	void toJson();
	LogoutZone(int timeStamp, std::string idUser, std::string idGame, int zone, int next);
};

