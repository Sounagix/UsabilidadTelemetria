// Tester.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tracker.h"
#include "AllEvents.h"

int main()
{
	Tracker* instance = Tracker::GetInstance();
	if (!instance->Init(PersistenceType::FILE)) {
		std::cout << "Error al inicializar el tracker\n";
		return -1;
	}
	
	std::cout << "Inicializacion completa\n";

	// TrackerEvent de prueba - Es un bean asi que se setean los datos
	OpenInv* openInv = (OpenInv*)(Tracker::CreateNewEvent(0, "a", "a", (int)EventType::OpenInv));
	openInv->setTimeOut(10);
	openInv->setEquipPot(true);

	// Envio del evento
	instance->TrackEvent(openInv);

	// Volcado de los datos
	if (!instance->End()) {
		std::cout << "Error al realizar el volcado de los datos\n";
		return -2;
	}
	
	system("pause");
}
