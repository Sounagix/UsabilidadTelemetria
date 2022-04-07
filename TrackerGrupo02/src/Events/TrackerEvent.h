#pragma once
#include <iostream>

enum eventype
{
	Login,
	Logout,
	LoginZone,
	LogoutZone,
	OpenInv,
	OpenSkills,
	OpenChest,
	OpenShop,
	UseSkill,
	UsePot,
	TutoTask,
};


class TrackerEvent
{
protected:
	eventype _event;
	std::string _idUser;
	std::string _idGame;
	int _timestamp;
public:

	TrackerEvent(int timeStamp,std::string idUser,std::string idGame);
	void setEv(eventype event) { _event = event; }
	void setIdUser(std::string id) { _idUser = id; }
	void setIdGame(std::string id) { _idGame = id; }
	void setTimestamp(int timeStamp) { _timestamp = timeStamp; }

	eventype getEvent() { return _event; }
	std::string getIdUser() { return _idUser; }
	std::string getIdGame() { return _idGame; }
	int getTimeStamp() { return _timestamp; }

	virtual void toJson();
};

