#include "TrackerEvent.h"

void TrackerEvent::setEv(EventType event)
{
	_event = event;
}

void TrackerEvent::setIdUser(std::string id)
{
	_idUser = id;
}

void TrackerEvent::setIdGame(std::string id)
{
	_idGame = id;
}

void TrackerEvent::setTimestamp(int timeStamp)
{
	_timestamp = timeStamp;
}

EventType TrackerEvent::getEvent()
{
	return _event;
}

std::string TrackerEvent::getIdUser()
{
	return _idUser;
}

std::string TrackerEvent::getIdGame()
{
	return _idGame;
}

int TrackerEvent::getTimeStamp()
{
	return _timestamp;
}
