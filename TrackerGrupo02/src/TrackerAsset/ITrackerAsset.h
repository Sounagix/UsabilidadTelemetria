#pragma once

class TrackerEvent;

class ITrackerAsset
{
public:
	virtual bool accept(TrackerEvent trackerEvent);
};



