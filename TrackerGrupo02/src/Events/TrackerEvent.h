#pragma once
#include <iostream>

enum class EventType : int
{
	Login = 0,
	Logout = 1,
	LoginZone = 2,
	LogoutZone = 3,
	OpenInv = 4,
	OpenSkills = 5,
	OpenChest = 6,
	OpenShop = 7,
	UseSkill = 8,
	UsePot = 9,
	TutoTask = 10,

	NONE = 100
};


class TrackerEvent
{
protected:
	EventType _event = EventType::NONE;
	std::string _idUser = "none";
	std::string _idGame = "none";
	int _timestamp = 0;
	TrackerEvent() {};

public:

	//-------------------SET---------------//
	void setEv(EventType event);
	void setIdUser(std::string id);
	void setIdGame(std::string id);
	void setTimestamp(int timeStamp);

	//-------------------GET---------------//
	EventType getEvent();
	std::string getIdUser();
	std::string getIdGame();
	int getTimeStamp();

	//-------------------OTHER---------------//
	virtual std::string toJson() { return ""; };
};

