#pragma once
#include "IPersistence.h"

class Tracker
{
private:
	static Tracker instance;

	Tracker();

public:
	
	Tracker GetInstance();
};

