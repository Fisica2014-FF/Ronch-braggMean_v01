//============================================================================
// Name        : ECLIPSE_MARS_PROJECT_CPP11.cpp
// Author      : Francesco Forcher
// Version     : 0.1
// Copyright   : All rights reserved © 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#include "dbg_macro.h"
#include "Event.h"

using namespace std;

//const has static linkage by default, so we must use explicitly extern here.
extern const unsigned int MIN_POINTS = 120;

void clear(Event* ev);

Event* read(std::ifstream& ifs);

void dump(const Event& ev);

bool add(const Event& ev, long sumenergies[], unsigned long sumsquares[],
		long min_en, long max_en);

int main(int argc, char* argv[]) {
	using namespace std;

	//Read file name, see DBG macro at the start.
	DBG(const char* filename = "./bragg_events.txt";
		, const char* filename = argv[1];)

	//Open file
	ifstream ifs(filename);
	long* sumenergies = new long[MIN_POINTS];
	unsigned long* sumsquares = new unsigned long[MIN_POINTS];
	double* meanenergy;
	double* rmsenergy;

	//Inizialize at zero the arrays.
	for (unsigned i = 0; i < MIN_POINTS; ++i) {
		sumenergies[i] = 0;
		sumsquares = 0;
	}

	/*
	 Event* event;
	 while (ifs) {
	 event = read(ifs);
	 if (event) {
	 dump(*event);
	 clear(event);
	 }
	 }*/

	return 0;
}

