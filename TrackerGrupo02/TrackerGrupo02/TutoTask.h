#pragma once
#include "TrackerEvent.h"

class TutoTask : public TrackerEvent
{
private:
	std::string _name;
	int _timeOut;
public:
	void toJson();
	TutoTask(int timeStamp, std::string idUser, std::string idGame,std::string name, int timeOut);
};

