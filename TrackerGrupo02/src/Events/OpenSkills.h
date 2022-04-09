#pragma once
#include "TrackerEvent.h"

class OpenSkills : public TrackerEvent
{
private:
	bool _points;
public:
	std::string toJson();
	OpenSkills();

	void setPoints(bool points);
	bool getPoints();
};

