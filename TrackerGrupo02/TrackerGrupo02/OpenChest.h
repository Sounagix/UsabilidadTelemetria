#pragma once
#include "TrackerEvent.h"

class OpenChest : public TrackerEvent
{
private:
	bool _openInv;
public:
	void toJson();
	OpenChest(int timeStamp, std::string idUser, std::string idGame, bool openInv);
};

