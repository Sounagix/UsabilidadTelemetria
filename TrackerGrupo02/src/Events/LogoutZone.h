#pragma once
#include "TrackerEvent.h"

class LogoutZone : public TrackerEvent
{
private:
	int _zone = 0;
	int _next = 0;
public:
	std::string toJson();
	LogoutZone();

	void setZone(int zone);
	void setNext(int next);
	int getZone();
	int getNext();
};

