/*******************************************************************************
 File name:		  airportDriver.c
 Author:        Mike Rapacon
 Date:          11/13/15
 Class:         CS300
 Assignment:    Airport
 Purpose:       File contains the driver for Airplane
 ******************************************************************************/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/airport.h"


int main ()
{
	Queue takeoffQueue;
	PriorityQueue landingQueue;
	FILE *pFile;
	bool bEnd = false;
	queueCreate (&takeoffQueue);
	pqueueCreate (&landingQueue);
	pFile = fopen ("data/data.txt", "r");
	if (NULL == pFile)
	{
		printf ("ERROR: FILE NOT OPEN\n Program Exiting");
		exit (EXIT_FAILURE);
	}
	int clock = 1;
	do
	{
		if (clock == 1 || clock % 20 == 1)
		{
			printHeading ();
		}
		printTime (clock);
		readLine (&takeoffQueue, &landingQueue, pFile, clock);
		printFuel ();
		decreaseFuel (&landingQueue);
		runway (&takeoffQueue, &landingQueue, clock);
		checkCrash (&landingQueue);
		listLengths (&takeoffQueue, &landingQueue);
		printf ("\n");
		clock++;
		checkEmpty (&takeoffQueue, &landingQueue, &bEnd);
	} while (!feof (pFile) || !bEnd);
	printStats ();
	queueTerminate (&takeoffQueue);
	pqueueTerminate (&landingQueue);
	fclose (pFile);
	printf ("\nProcess Complete");
	return 0;
}

