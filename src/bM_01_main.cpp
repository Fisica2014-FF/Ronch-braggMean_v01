//============================================================================
// Name        : ECLIPSE_MARS_PROJECT_CPP11.cpp
// Author      : Francesco Forcher
// Version     : 0.1
// Copyright   : All rights reserved © 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>

#include "dbg_macro.h"
#include "Event.h"

using namespace std;

//const has static linkage by default, so we must use explicitly extern here.
extern const unsigned MIN_POINTS = 120;

void clear(Event* ev);

Event* read(std::ifstream& ifs);

void dump(const Event& ev);

bool add(const Event& ev, long sumenergies[], unsigned long sumsquares[],
		int min_en, int max_en);

void stat(const unsigned numevents, const unsigned numpoints,
		long sumenergies[], unsigned long sumsquares[], double meanenergies[],
		double rmsenergies[]);

int main(int argc, char* argv[]) {
	using namespace std;

	//Read file name, see DBG macro
	DBG(const char* filename = "./bragg_events.txt";
		, const char* filename = argv[1];)

	//Open file
	ifstream ifs(filename);
	long* sumenergies = new long[MIN_POINTS];
	unsigned long* sumsquares = new unsigned long[MIN_POINTS];
	double* meanenergies = new double[MIN_POINTS];
	double* rmsenergies = new double[MIN_POINTS];

	//Inizialize at zero the arrays.
	for (unsigned i = 0; i < MIN_POINTS; ++i) {
		sumenergies[i] = 0;
		sumsquares[i] = 0;
	}

	Event* event;
	bool is_in_range;
	unsigned counter_valid_events = 0;
	//Read the file and do the statistics.
	while (ifs) {
		event = read(ifs);
		if (event) {
			is_in_range = add(*event, sumenergies, sumsquares, 6000, 7500);
			//If event is in range increment the counter.
			if (is_in_range) {
				++counter_valid_events;
			}
			clear(event);
		}
	}

	stat(counter_valid_events, MIN_POINTS, sumenergies, sumsquares,
			meanenergies, rmsenergies);

	//Print the four arrays
	cout << "Point     TotEnergy  TotSquares MeanEnergy     RMS" << endl;
	for (unsigned i = 0; i < MIN_POINTS; ++i) {
		printf("%9u %9i  %9u  %9f %9f",i+1,sumenergies[i],sumsquares[i],meanenergies[i],rmsenergies[i]);
		cout << endl;
	}

	delete[] sumenergies;
	delete[] sumsquares;
	delete[] meanenergies;
	delete[] rmsenergies;
	return 0;
}

