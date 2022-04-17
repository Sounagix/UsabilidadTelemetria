#include "Tracker.h"
#include "AllEvents.h"
#include "FilePersistence.h"
#include <chrono>

Tracker* Tracker::_instance;
IPersistence* Tracker::_persistenceObject;
std::bitset<(uint64_t)EventInfo::EventType::NUM_EVENTS> Tracker::_bitMaskEvents;

Tracker::Tracker() {}

void Tracker::DefaultBitMask() {
	std::string strAux;
	for (int i = 0; i < (uint64_t)EventInfo::EventType::NUM_EVENTS; ++i)
		strAux += "1";

	std::bitset<(uint64_t)EventInfo::EventType::NUM_EVENTS> aux(strAux);
	_bitMaskEvents = aux;
}

bool Tracker::Init(PersistenceType persistType, TypeOfFile fileType, std::string pathFile)
{
	if (_instance->_persistenceObject != nullptr) {
		std::cout << "El Tracker ya se ha inicializado...\n";
		return false;
	}

	switch (persistType)
	{
	case PersistenceType::FILE:
		_instance->_persistenceObject = new FilePersistence(pathFile);
		break;
	case PersistenceType::SERVER:
		// TODO: Crearlo de forma SERVER
		std::cout << "Server WIP...\n";
		return false;
		break;
	default:
		std::cout << "Formato no reconocido " << (int)persistType << "\n";
		return false;
		break;
	}
	DefaultBitMask();
	return _instance->_persistenceObject->init(fileType);
}

bool Tracker::End()
{
	if (_instance == nullptr) {
		std::cout << "Error al querer volcar datos: Instancia no inicializada\n" << std::endl;
		return false;
	}
#ifdef DEBUG
	std::cout << "Volcando los datos...\n";
#endif
	try {
		_instance->_persistenceObject->flush();
	}
	catch (std::exception e) {
		std::cout << "Error volcando los datos:\n" << e.what() << std::endl;
		return false;
	}

	return true;
}

void Tracker::TrackEvent(TrackerEvent* newEvent)
{
	if (_instance == nullptr) {
		std::cout << "Error en el envío de datos: Instancia no inicializada\n" << std::endl;
		return;
	}

	// Comprobacion sobre si el evento esta activado
	if (_bitMaskEvents[(int)newEvent->getEventType()] == 1)
		_instance->_persistenceObject->send(newEvent);
	else {
		delete newEvent;
		newEvent = nullptr;
	}
}

TrackerEvent* Tracker::CreateNewEvent(long long timeStamp, std::string idUser, std::string idSesion, int eType)
{
	TrackerEvent* newEvent;

	switch (eType)
	{
	case (int)EventInfo::EventType::Login:
		newEvent = new Login();
		break;
	case (int)EventInfo::EventType::Logout:
		newEvent = new Logout();
		break;
	case (int)EventInfo::EventType::LoginZone:
		newEvent = new LoginZone();
		break;
	case (int)EventInfo::EventType::LogoutZone:
		newEvent = new LogoutZone();
		break;
	case (int)EventInfo::EventType::OpenInv:
		newEvent = new OpenInv();
		break;
	case (int)EventInfo::EventType::OpenSkills:
		newEvent = new OpenSkills();
		break;
	case (int)EventInfo::EventType::OpenChest:
		newEvent = new OpenChest();
		break;
	case (int)EventInfo::EventType::OpenShop:
		newEvent = new OpenShop();
		break;
	case (int)EventInfo::EventType::UseSkill:
		newEvent = new UseSkill();
		break;
	case (int)EventInfo::EventType::UsePot:
		newEvent = new UsePot();
		break;
	case (int)EventInfo::EventType::TutoTask:
		newEvent = new TutoTask();
		break;
	default:
		std::cout << "Error al generar evento\n";
		return nullptr;
		break;
	}

	newEvent->setEv((EventInfo::EventType)eType);
	newEvent->setTimestamp(timeStamp);
	newEvent->setIdUser(idUser);
	newEvent->setIdSesion(idSesion);

	return newEvent;
}

void Tracker::Free()
{
	if (_instance == nullptr) {
		std::cout << "No se puede eliminar una instancia sin inicializar\n";
		return;
	}

	delete _instance->_persistenceObject;
	delete _instance;
}

Tracker* Tracker::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new Tracker();
	}

	return _instance;
}

long long Tracker::GetTimeStamp()
{
	return std::chrono::duration_cast<std::chrono::seconds>(
		std::chrono::system_clock::now().time_since_epoch()).count();;
}

void Tracker::SetBitMaskEvents(const std::string bits, bool flip) {
	std::size_t found = bits.find_first_not_of("10");
	if (found != std::string::npos) {
		std::cout << "Error en la posición %d del mapa de bits, se creará uno por defecto\n", found;
		DefaultBitMask();
		return;
	}

	if (bits.length() != (uint64_t)EventInfo::EventType::NUM_EVENTS) {
		std::cout << "Warning en el mapa de bits, posible pérdida de datos. Tamaño esperado: %d   Tamaño recibido: %d\n",
			(uint64_t)EventInfo::EventType::NUM_EVENTS, bits.length();
	}

	std::string strAux = bits;
	if (flip) std::reverse(strAux.begin(), strAux.end());
	std::bitset<(uint64_t)EventInfo::EventType::NUM_EVENTS> aux(strAux);
	_bitMaskEvents = aux;
}