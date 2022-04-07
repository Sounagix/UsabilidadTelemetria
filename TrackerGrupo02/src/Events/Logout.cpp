#include "Logout.h"

void Logout::toJson()
{
}

Logout::Logout(int timeStamp, std::string idUser, std::string idGame)
	:TrackerEvent(timeStamp, idUser, idGame)
{
	_event = eventype::Logout;
}
