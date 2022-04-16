#pragma once
#include "TrackerEvent.h"

class OpenInv : public TrackerEvent
{
private:
	long long _timeOut = 0;
	bool _equipPot = false;

public:
	std::string toJson();
	OpenInv();

	void setTimeOut(long long timeOut);
	void setEquipPot(bool equipPot);
	long long getTimeOut();
	bool getEquipPot();
};

