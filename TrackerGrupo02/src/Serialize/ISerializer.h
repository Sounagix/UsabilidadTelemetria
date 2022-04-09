#pragma once
#include <iostream>

class TrackerEvent;

class ISerializer
{
public:
	virtual std::string serialize(TrackerEvent* eventToSer) = 0;
};

