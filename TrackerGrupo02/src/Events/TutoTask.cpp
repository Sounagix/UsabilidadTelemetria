#include "TutoTask.h"

void TutoTask::toJson()
{
}

TutoTask::TutoTask(int timeStamp, std::string idUser, std::string idGame, std::string name, int timeOut)
	:TrackerEvent(timeStamp, idUser, idGame),_name(name),_timeOut(timeOut)
{
	_event = eventype::TutoTask;
}
