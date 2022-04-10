#include "FilePersistence.h"
#include "JsonSerializer.h"
#include "AllEvents.h"
#include <iostream>
#include <filesystem>

bool FilePersistence::init(TypeOfFile type)
{
	switch (type)
	{
	case TypeOfFile::Json:
		_serializer = new JsonSerializer();
		break;
	case TypeOfFile::Csv:
		std::cout << "Sigan viendo...\n";
		break;
	default:
		std::cout << "Formato no reconocido...\n";
		return false;
		break;
	}

	return true;
}

void FilePersistence::send(TrackerEvent* trackEvent)
{
	_eventQueue.push(trackEvent);
}

void FilePersistence::flush(std::string pathFile)
{
	// TODO: Decirle al Serialize que serialice los datos del TrackerEvent
	// para posteriormente recogerlos y crear el archivo Json
	int i = 0;
	while (!_eventQueue.empty())
	{
		TrackerEvent* e = _eventQueue.front();
		std::string json = _serializer->serialize(e);
		// TODO: Parsear al archivo de texto
		//Path del directorio
		std::string dir = pathFile + e->getEventName();
		//Si no existe creamos el directorio
		if (!std::filesystem::exists(dir))
		{
			std::filesystem::create_directory(dir);
		}
		//Archivos creados en el directorio
		int fileCount = std::distance(std::filesystem::directory_iterator(dir), std::filesystem::directory_iterator{});

		std::string aux = dir +"/"+dir + std::to_string(fileCount);
		
		std::ofstream file( aux +".json");

		file << json ;
		file.close();
		
		_eventQueue.pop();
		delete e;
		e = nullptr;
	}
}
