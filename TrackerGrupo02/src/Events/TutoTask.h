#pragma once
#include "TrackerEvent.h"

class TutoTask : public TrackerEvent
{
private:
	std::string _name = "";
	long long _timeOut = 0;
public:
	std::string toJson();
	TutoTask();

	void setName(std::string name);
	void setTimeOut(long long t);
	std::string getName();
};

