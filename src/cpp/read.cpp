/*
 * read.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include <iostream>
#include <fstream>

#include "../Event.h"

// Read a new Event from file ifs and return a pointer to it.
Event* read(std::ifstream& ifs) {
	using namespace std;

	Event* ev = new Event;
	// Being ev a very small structure, i prefer to always allocate it before
	// rather than complicate the program's logic trying to read
	// from file into temporary variables before (potentially) creating it.
	if (ifs >> ev->event_ID) {
		ifs >> ev->number_of_points;
		ev->energies = new int[ev->number_of_points];
		for (unsigned int i = 0; i < ev->number_of_points; ++i) {
			ifs >> ev->energies[i];
		}
	} else {
		//We cannot do clear(ev) here, because here ev has undefined values.
		delete ev;
		ev = nullptr;
	}

	return ev;
}

