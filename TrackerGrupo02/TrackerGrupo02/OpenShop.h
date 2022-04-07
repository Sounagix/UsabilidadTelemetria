#pragma once
#include "TrackerEvent.h"

class OpenShop : public TrackerEvent
{
public:
	void toJson();
	OpenShop(int timeStamp, std::string idUser, std::string idGame);
};

