#pragma once
#include "../src/TrackerEvent.h"

class Login : public TrackerEvent 
{
public:
	void toJson();
	Login(int time,string idu,string idg);
};

