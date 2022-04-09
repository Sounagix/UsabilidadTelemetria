#include "OpenInv.h"

std::string OpenInv::toJson()
{
	return "Sigan viendo...";
}

OpenInv::OpenInv() :TrackerEvent() {}

void OpenInv::setTimeOut(int timeOut)
{
	_timeOut = timeOut;
}

void OpenInv::setEquipPot(bool equipPot)
{
	_equipPot = equipPot;
}

int OpenInv::getTimeOut()
{
	return _timeOut;
}

bool OpenInv::getEquipPot()
{
	return _equipPot;
}