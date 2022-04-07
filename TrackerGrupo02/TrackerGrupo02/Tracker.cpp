#include "Tracker.h"

Tracker::Tracker() {

	if (instance == nullptr) {
		instance = this;
	}
	else {
		delete this;
	}
}