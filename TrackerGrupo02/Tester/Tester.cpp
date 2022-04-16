// Tester.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tracker.h"
#include "AllEvents.h"

#define PATH_FILE "./"

int main()
{
	setlocale(LC_ALL, "");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

	Tracker* _instance = Tracker::GetInstance();
	if (!_instance->Init(PersistenceType::FILE, TypeOfFile::Json, PATH_FILE)) {
		std::cout << "Error al inicializar el tracker\n";
		return -1;
	}

	std::cout << "Inicializacion completa\n";

	// TrackerEvents de prueba
	// Envio del evento
	OpenInv* openInv = (OpenInv*)(Tracker::CreateNewEvent(0, "a", "a", (int)EventInfo::EventType::OpenInv));
	openInv->setTimeOut(10);
	openInv->setEquipPot(true);
	_instance->TrackEvent(openInv);

	// Envio del evento
	openInv = (OpenInv*)(Tracker::CreateNewEvent(1, "b", "b", (int)EventInfo::EventType::OpenInv));
	openInv->setTimeOut(11);
	openInv->setEquipPot(false);
	_instance->TrackEvent(openInv);

	// Envio del evento
	UseSkill* useSkill = (UseSkill*)(Tracker::CreateNewEvent(0, "a", "a", (int)EventInfo::EventType::UseSkill));
	useSkill->setZone(11);
	_instance->TrackEvent(useSkill);

	// Volcado de los datos
	if (!_instance->End()) {
		Tracker::Free();
		return -2;
	}

	try
	{
		Tracker::Free();
	}
	catch (std::exception e)
	{
		std::cout << "Error en la liberacion de recursos del Tracker:\n" << e.what() << std::endl;
		return -3;
	}

	std::cout << "Success\n";
	return 0;
}
