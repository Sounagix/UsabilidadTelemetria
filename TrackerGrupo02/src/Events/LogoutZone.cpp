#include "LogoutZone.h"

void LogoutZone::toJson()
{

}

LogoutZone::LogoutZone(int timeStamp, std::string idUser, std::string idGame, int zone, int next)
	:TrackerEvent(timeStamp, idUser, idGame), _zone(zone), _next(next)
{
	_event = eventype::LogoutZone;
}
