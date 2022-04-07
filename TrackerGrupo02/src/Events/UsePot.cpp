#include "UsePot.h"

void UsePot::toJson()
{
}

UsePot::UsePot(int timeStamp, std::string idUser, std::string idGame)
	:TrackerEvent(timeStamp, idUser, idGame)
{
	_event = eventype::UsePot;
}

