#pragma once
#include "TrackerEvent.h"

class OpenSkills : public TrackerEvent
{
private:
	bool _points = false;
public:
	std::string toJson();
	OpenSkills();

	void setPoints(bool points);
	bool getPoints();
};

