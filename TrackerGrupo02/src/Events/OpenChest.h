#pragma once
#include "TrackerEvent.h"

class OpenChest : public TrackerEvent
{
private:
	bool _openInv = false;
public:
	std::string toJson();
	OpenChest();

	void setOpenInv(bool openInv);
	bool getOpenInv();
};

