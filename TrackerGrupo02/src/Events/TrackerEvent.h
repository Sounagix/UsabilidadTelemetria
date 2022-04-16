#pragma once
#include <iostream>
#include "jute.h"
#include "EventInfo.h"

class TrackerEvent
{
protected:
	EventInfo::EventType _event = EventInfo::EventType::NONE;
	std::string _idUser = "none";
	std::string _idGame = "none";
	long long _timestamp = 0;
	jute::jValue mainJson;
	TrackerEvent() {};
	virtual void commonJson();
public:
	~TrackerEvent() {}

	//-------------------SET---------------//
	void setEv(EventInfo::EventType event);
	void setIdUser(std::string id);
	void setIdGame(std::string id);
	void setTimestamp(long long timeStamp);

	//-------------------GET---------------//
	EventInfo::EventType getEventType();
	std::string getIdUser();
	std::string getIdGame();
	long long getTimeStamp();

	//-------------------OTHER---------------//
	virtual std::string toJson() { return ""; };
	
	//std::string getEventName()
	//{
	//	if (_event == EventInfo::EventType::NONE)return "NONE";
	//	return std::string(EventInfo::eventName[(int)_event]);
	//}
};

