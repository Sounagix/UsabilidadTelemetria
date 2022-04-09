#include "JsonSerializer.h"
#include "TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* eventToSer)
{
    return eventToSer->toJson();
}
