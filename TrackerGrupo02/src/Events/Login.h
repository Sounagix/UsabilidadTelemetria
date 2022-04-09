#pragma once
#include "TrackerEvent.h"

class Login : public TrackerEvent 
{
public:
	std::string toJson();
	Login();
};

