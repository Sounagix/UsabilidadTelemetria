#pragma once
#include "TrackerEvent.h"

class UseSkill : public TrackerEvent
{
private:
	int _zone = 0;
public:
	std::string toJson();
	UseSkill();

	void setZone(int zone);
	int getZone();
};

