#pragma once
#include "TrackerEvent.h"

class Logout : public TrackerEvent
{
public:
	void toJson();
	Logout(int timeStamp, std::string idUser, std::string idGame);
};

