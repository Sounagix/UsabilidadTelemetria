#pragma once
#include "TrackerEvent.h"

class TutoTask : public TrackerEvent
{
private:
	std::string _name;
	int _timeOut;
public:
	std::string toJson();
	TutoTask();

	void setName(std::string name);
	std::string getName();
};

