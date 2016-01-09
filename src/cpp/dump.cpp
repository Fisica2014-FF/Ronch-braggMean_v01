/*
 * dump.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include <iostream>

#include "../Event.h"

// Print to standard output the Event ev.
void dump(const Event& ev) {
	using namespace std;

	// If the event has no energy points it is invalid
	if (ev.number_of_points == 0)
		return;

	cout << "Event " << ev.event_ID << ": " << ev.number_of_points << " points"
			<< endl;
	for (unsigned i = 0; i < ev.number_of_points; ++i) {
		cout << "    " << ev.energies[i];

		// Digression: It should be noted that on modern processor complicated conditions
		// inside repeated blocks (like a for loop) are not cpu-intensive if
		// they are almost always true or false, thanks to branch prediction.
		// Anyway, since logic operators like && (=and) uses short-circuit evalutation,
		// it's better to put them in order of probability to have different values during
		// the cycle.
		if (i % 12 == 0 and i != 0) {
			cout << endl;
		}
	}
	return;
}

