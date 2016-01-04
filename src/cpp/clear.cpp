/*
 * clear.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include "../Event.h"

// Clear the memory of Event* ev
void clear(Event* ev) {
	delete[] ev->energies;
	delete ev;
	ev = nullptr;
}

