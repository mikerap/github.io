/*******************************************************************************
 File name:		  airport.h
 Author:        Mike Rapacon
 Date:          11/13/15
 Class:         CS300
 Assignment:    Airport
 Purpose:       File contains the function definitions for Airplane ADT
 ******************************************************************************/

#ifndef INCLUDE_AIRPORT_H_
#define INCLUDE_AIRPORT_H_

#include <stdbool.h>
#include "../../DynamicQueue/include/queue.h"

void printHeading (); //print heading first and every 20th line
void readLine (QueuePtr psQueue, PriorityQueuePtr psPriorityQueue,
							 FILE *pFile, int clock);
void decreaseFuel (PriorityQueuePtr psLandingQueue);
void printTime (int time);
void printTakeoff (QueuePtr psTakeoffQueue);
void runway (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue,
						 int clock);
void printFuel ();
void checkCrash (PriorityQueuePtr psLandingQueue);
void listLengths (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue);
void checkEmpty (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue,
									 bool *bEnd);
void printStats ();

#endif /* INCLUDE_AIRPORT_H_ */
