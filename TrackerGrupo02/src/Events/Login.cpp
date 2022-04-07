#include "Login.h"

void Login::toJson()
{

}

Login::Login(int timeStamp, std::string idUser, std::string idGame)
	:TrackerEvent(timeStamp, idUser, idGame)
{
	_event = eventype::Login;
}
