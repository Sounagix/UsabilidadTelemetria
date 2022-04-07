#include "Logout.h"

void Logout::toJson()
{
}

Logout::Logout(int time, string idu, string idg) :TrackerEvent(timestamp, idu, idg)
{
	ev = eventype::Logout;
}
