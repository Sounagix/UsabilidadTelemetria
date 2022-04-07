#pragma once
#include "TrackerEvent.h"

class OpenInv : public TrackerEvent
{
private:
	int _timeOut;
	bool _equipPot;
public:
	void toJson();
	OpenInv(int timeStamp, std::string idUser, std::string idGame, int timeOut, bool equipPot);
};

