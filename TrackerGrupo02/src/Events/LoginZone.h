#pragma once
#include "TrackerEvent.h"

class LoginZone : public TrackerEvent
{
private:
	int _zone = 0;
	bool _completed = false;
public:
	std::string toJson();
	LoginZone();

	void setZone(int zone);
	void setCompleted(bool completed);
	int getZone();
	bool getCompleted();
};

