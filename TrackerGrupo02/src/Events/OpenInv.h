#pragma once
#include "TrackerEvent.h"

class OpenInv : public TrackerEvent
{
private:
	int _timeOut = 0;
	bool _equipPot = false;

public:
	std::string toJson();
	OpenInv();

	void setTimeOut(int timeOut);
	void setEquipPot(bool equipPot);
	int getTimeOut();
	bool getEquipPot();
};

