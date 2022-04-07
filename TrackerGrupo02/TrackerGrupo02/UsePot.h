#pragma once
#include "TrackerEvent.h"

class UsePot : public TrackerEvent
{
public:
	void toJson();
	UsePot(int timeStamp, std::string idUser, std::string idGame);
};

