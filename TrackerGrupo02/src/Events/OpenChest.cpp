#include "OpenChest.h"

std::string OpenChest::toJson()
{
	return " ";
}

void OpenChest::setOpenInv(bool openInv)
{
	_openInv = openInv;
}

bool OpenChest::getOpenInv()
{
	return _openInv;
}

OpenChest::OpenChest() :TrackerEvent() {}
