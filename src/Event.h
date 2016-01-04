/*
 * Event.h
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#ifndef EVENT_H_
#define EVENT_H_

// Struct which represent an Event.
struct Event {
	unsigned int event_ID;
	unsigned int number_of_points;
	int* energies;
};

#endif /* EVENT_H_ */
