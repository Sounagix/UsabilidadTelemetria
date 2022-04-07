#pragma once
#include "TrackerEvent.h"

class Login : public TrackerEvent 
{
public:
	void toJson();
	Login(int timeStamp,std::string idUser,std::string idGame);
};

