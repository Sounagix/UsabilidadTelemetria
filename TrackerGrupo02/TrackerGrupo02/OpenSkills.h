#pragma once
#include "TrackerEvent.h"

class OpenSkills : public TrackerEvent
{
private:
	bool _points;
public:
	void toJson();
	OpenSkills(int timeStamp, std::string idUser, std::string idGame, bool points);
};

