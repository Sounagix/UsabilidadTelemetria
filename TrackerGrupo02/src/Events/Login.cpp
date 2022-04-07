#include "Login.h"

void Login::toJson()
{

}

Login::Login(int time, string idu, string idg) :TrackerEvent(timestamp, idu, idg)
{
	ev = eventype::Login;
}
