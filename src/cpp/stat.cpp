/*
 * stat.cpp
 *
 *  Created on: 04 gen 2016
 *      Author: francesco
 */

//TODO extern const unsigned MIN_POINTS;
#include <cmath>

/* For every point until numpoints, using sumenergies and sumsquares, calculate
 * the mean and rms of the numevents valid events, putting them in their
 * respective arrays meanenergies and rmsenergies.
 */
void stat(const unsigned numevents, const unsigned numpoints,
		long sumenergies[], unsigned long sumsquares[], double meanenergies[],
		double rmsenergies[]) {
	using namespace std;

	//For every point, calculate the mean and rms
	for (unsigned i = 0; i < numpoints; ++i) {
		meanenergies[i] = sumenergies[i] / double(numevents);
		rmsenergies[i] = sqrt(
				sumsquares[i] / double(numevents) - pow(
						sumenergies[i] / double(numevents), 2));
	}

	return;
}
