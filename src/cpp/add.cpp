/*
 * add.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include "../Event.h"

extern const unsigned int MIN_POINTS;

// Compute total energy of ev and, if min_en < totalenergy < max_en,
// update sumenergies and sumsquares accordingly
bool add(const Event& ev, long sumenergies[], unsigned long sumsquares[],
		long min_en, long max_en) {
	long totalenergy = 0;

	//Compute total energy
	for (unsigned i = 0; i < MIN_POINTS; ++i) {
		totalenergy += ev.energies[i];
	}

	//
	if (totalenergy > min_en and totalenergy < max_en) {
		for (unsigned i = 0; i < MIN_POINTS; ++i) {
			sumenergies[i] += ev.energies[i];
			sumsquares[i] += ev.energies[i] * ev.energies[i];
			return true;
		}
	} else {
		return false;
	}

}

