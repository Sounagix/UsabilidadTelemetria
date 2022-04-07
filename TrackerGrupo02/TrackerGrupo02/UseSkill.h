#pragma once
#include "TrackerEvent.h"

class UseSkill : public TrackerEvent
{
private:
	int _zone;
public:
	void toJson();
	UseSkill(int timeStamp, std::string idUser, std::string idGame, int zone);
};

