#include "OpenSkills.h"

void OpenSkills::toJson()
{
}

OpenSkills::OpenSkills(int timeStamp, std::string idUser, std::string idGame, bool points)
	:TrackerEvent(timeStamp, idUser, idGame),_points(points)
{
	_event = eventype::OpenSkills;
}
