#include "TrackerEvent.h"


void TrackerEvent::commonJson()
{
	mainJson = (jute::jType::JOBJECT);
	jute::jValue str(jute::jType::JSTRING);
	str.set_string(_idUser);
	mainJson.add_property("idUser", str);
	str.set_string(_idGame);
	mainJson.add_property("idGame", str);

	jute::jValue num(jute::jType::JNUMBER);
	num.set_string(std::to_string((int)_timestamp));
	mainJson.add_property("timestamp", num);
	num.set_string(std::to_string((int)_event));
	mainJson.add_property("eventType", num);

}

void TrackerEvent::setEv(EventInfo::EventType event)
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

EventInfo::EventType TrackerEvent::getEvent()
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

