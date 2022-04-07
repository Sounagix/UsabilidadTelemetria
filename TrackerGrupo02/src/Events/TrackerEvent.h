#pragma once
#include <iostream>

using namespace std;


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
	eventype ev;
	string idUser;
	string idGame;
	int timestamp;
public:

	TrackerEvent(int time,string idu,string idg);
	void setEv(eventype e) { ev = e; }
	void setIdUser(string id) { idUser = id; }
	void setIdGame(string id) { idGame = id; }
	void setTimestamp(int time) { timestamp = time; }

	eventype getEvent() { return ev; }
	string getIdUser() { return idUser; }
	string getIdGame() { return idGame; }
	int getTimeStamp() { return timestamp; }

	virtual void toJson();
};

