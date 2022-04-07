#include "OpenInv.h"

void OpenInv::toJson()
{

}

OpenInv::OpenInv(int timeStamp, std::string idUser, std::string idGame, int timeOut, bool equipPot)
	:TrackerEvent(timeStamp, idUser, idGame), _timeOut(timeOut), _equipPot(equipPot)
{
	_event = eventype::OpenInv;
}
