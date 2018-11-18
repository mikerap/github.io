/*******************************************************************************
 File name:		  airport.c
 Author:        Mike Rapacon
 Date:          11/13/15
 Class:         CS300
 Assignment:    Airport
 Purpose:       File contains the function implementation for Airplane ADT
 ******************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../DynamicQueue/src/queue.c"

int gTakeoffTotal, gLandTotal, gFuel1, gFuel2, gFuel3;
float gFlyingTime, gWaitTime, gTimeLeft = 0;
int gNumTakeoff, gNumLand, gNumEmergency, gNewCrashes, gCrashTotal = 0;

/****************************************************************************
 Function:      printHeading

 Description:   prints Airport heading

 Parameters:    none

 Returned:      none
****************************************************************************/
void printHeading ()
{
	char *separator = "|";
	char *print = "Planes Added";
	char *runways = "Runways";
	char *listLengths = "List  Lengths";
	printf ("%6s", separator);
	printf ("%23s", print);
	printf ("%13s", separator);
	printf ("%13s", runways);
	printf ("%7s", separator);
	printf ("%17s\n", listLengths);
	printf ("Time | Takeoff  Landing (Fuel Remaining) |");
	printf ("  1   2   3  Crash |");
	printf (" Takeoff  Landing\n");
	printf ("---- | -------  ------------------------ |");
	printf (" --- --- --- ----- |");
	printf (" -------  -------\n");
	return;
}

/****************************************************************************
 Function:      readLine

 Description:   reads in data from data/data.txt, inserts them into their
 	 	 	 	 	 	 	 	respective queues

 Parameters:    psTakeoffQueue - pointer to a non-priority queue, holds
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 planes that need to takeoff
 	 	 	 	 	 	 	 	psLandingQueue - pointer to a priority queue, holds planes
 	 	 	 	 	 	 	 									 that need to land
 	 	 	 	 	 	 	 	pFile 				 - pointer to file location
 	 	 	 	 	 	 	 	clock					 - int containing number of clock ticks

 Returned:      none
****************************************************************************/
void readLine (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue,
							 FILE *pFile, int clock)
{
	Q_DATATYPE qData;
	gFuel1 = 0; gFuel2 = 0; gFuel3 = 0;
	gNumLand = 0; gNumTakeoff = 0;
	if (!feof (pFile))
	{
		fscanf (pFile, "%d %d %d %d %d", &gNumTakeoff, &gNumLand, &gFuel1, &gFuel2, &gFuel3);
		printf ("%8d", gNumTakeoff);
		printf ("%8d", gNumLand);
		printf (" |");
		qData.intValue = (clock - 1);
		if (gNumLand > 0)
		{
			qData.priority = gFuel1;

			pqueueEnqueue (psLandingQueue, qData);
			gLandTotal++;
			if (gNumLand > 1)
			{
				qData.priority = gFuel2;
				pqueueEnqueue (psLandingQueue, qData);
				gLandTotal++;
				if (gNumLand > 2)
				{
					qData.priority = gFuel3;
					pqueueEnqueue (psLandingQueue, qData);
					gLandTotal++;
				}
			}
		}
		if (gNumTakeoff > 0)
		{
			qData.priority = 0;
			queueEnqueue (psTakeoffQueue, qData);
			gTakeoffTotal++;
			if (gNumTakeoff > 1)
			{
				queueEnqueue (psTakeoffQueue, qData);
				gTakeoffTotal++;
				if (gNumTakeoff > 2)
				{
					queueEnqueue (psTakeoffQueue, qData);
					gTakeoffTotal++;
				}
			}
		}
	}
	else
	{
		printf ("%8d", 0);
		printf ("%8d", 0);
		printf (" |");
	}
}

/****************************************************************************
 Function:      printTime

 Description:   prints the time

 Parameters:    time	-	number of clock ticks

 Returned:      none
****************************************************************************/
void printTime (int time)
{
	printf ("%4d", time);
	printf (" |");
}

/****************************************************************************
 Function:      runway

 Description:   determines which planes use the 3 runways

 Parameters:    psTakeoffQueue - pointer to a non-priority queue, holds
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 planes that need to takeoff
 	 	 	 	 	 	 	 	psLandingQueue - pointer to a priority queue, holds planes
 	 	 	 	 	 	 	 									 that need to land
 	 	 	 	 	 	 	 	clock					 - int containing number of clock ticks

 Returned:      none
****************************************************************************/
void runway (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue, int clock)
{
	gNewCrashes = 0;
	bool bTakeoff, bLanding = false;
	int i;
	Q_DATATYPE qPeek;
	pqueuePeek (psLandingQueue, &qPeek);
	while (qPeek.priority < 0)
	{
		gCrashTotal++;
		gNewCrashes++;
		pqueueDequeue (psLandingQueue, &qPeek);
		pqueuePeek (psLandingQueue, &qPeek);
	}
	for (i = 0; i < 3; i++)
	{
		pqueueIsEmpty (psLandingQueue, &bLanding);
		queueIsEmpty (psTakeoffQueue, &bTakeoff);
		pqueuePeek (psLandingQueue, &qPeek);
		if (!bLanding && qPeek.priority >= 0 && qPeek.priority < 4)
		{
			if (qPeek.priority == 0)
			{
				printf ("%4c", 'E');
				gFlyingTime += (clock - qPeek.intValue);
				pqueueDequeue (psLandingQueue, &qPeek);
				gNumEmergency++;
			}
			else
			{
				printf ("%4c", 'L');
				gFlyingTime += (clock - qPeek.intValue);
				gTimeLeft += qPeek.priority;
				pqueueDequeue (psLandingQueue, &qPeek);
			}
		}
		else if (!bTakeoff)
		{
			printf ("%4c", 'T');
			queueDequeue (psTakeoffQueue, &qPeek);
			gWaitTime += (clock - qPeek.intValue);
		}
		else if (bTakeoff && !bLanding)
		{
			printf ("%4c", 'L');
			gFlyingTime += (clock - qPeek.intValue);
			gTimeLeft += qPeek.priority;
			pqueueDequeue (psLandingQueue, &qPeek);
		}
		else
		{
			printf ("%4c", '-');
		}
	}
}

/****************************************************************************
 Function:      decreaseFuel

 Description:   decreases priority of planes still flying by 1

 Parameters:    psLandingQueue - pointer to a priority queue, holds planes
 	 	 	 	 	 	 	 									 that need to land

 Returned:      none
****************************************************************************/
void decreaseFuel (PriorityQueuePtr psLandingQueue)
{
	int change = -1;
	pqueueChangePriority (psLandingQueue, change);
}

/****************************************************************************
 Function:      printFuel

 Description:   prints the fuel amounts for new planes

 Parameters:    none

 Returned:      none
****************************************************************************/
void printFuel ()
{
	if (gNumLand == 0)
	{
		printf ("%6c", '-');
		printf ("%5c", '-');
		printf ("%5c", '-');
		printf (" |");
	}
	else
	{
		if (gNumLand == 1)
		{
			printf ("%6d", gFuel1);
			printf ("%5c", '-');
			printf ("%5c", '-');
			printf (" |");
		}
		else if (gNumLand == 2)
		{
			printf ("%6d", gFuel1);
			printf ("%5d", gFuel2);
			printf ("%5c", '-');
			printf (" |");
		}
		else
		{
			printf ("%6d", gFuel1);
			printf ("%5d", gFuel2);
			printf ("%5d", gFuel3);
			printf (" |");
		}
	}
}

/****************************************************************************
 Function:      checkCrash

 Description:   checks if any new crashes have occured

 Parameters:    psLandingQueue	-	pointer to queue containing planes that
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  still need to land

 Returned:      none
****************************************************************************/
void checkCrash (PriorityQueuePtr psLandingQueue)
{
	printf ("%6d", gNewCrashes);
	printf ("%2c", '|');
}

/****************************************************************************
 Function:      listLengths

 Description:   prints the lengths of the queues

 Parameters:    psTakeoffQueue - pointer to a non-priority queue, holds
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 planes that need to takeoff
 	 	 	 	 	 	 	 	psLandingQueue - pointer to a priority queue, holds planes
 	 	 	 	 	 	 	 									 that need to land

 Returned:      none
****************************************************************************/
void listLengths (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue)
{
	int sizeTakeoff, sizeLanding = 0;
	queueSize (psTakeoffQueue, &sizeTakeoff);
	pqueueSize (psLandingQueue, &sizeLanding);
	printf ("%8d", sizeTakeoff);
	printf ("%9d", sizeLanding);
}

/****************************************************************************
 Function:      checkEmpty

 Description:   checks if both queues are empty, determines if process
 	 	 	 	 	 	 	 	should continue

 Parameters:    psTakeoffQueue - pointer to a non-priority queue, holds
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 planes that need to takeoff
 	 	 	 	 	 	 	 	psLandingQueue - pointer to a priority queue, holds planes
 	 	 	 	 	 	 	 									 that need to land
 	 	 	 	 	 	 	 	bEnd					 - bool determing if process should end

 Returned:      none
****************************************************************************/
void checkEmpty (QueuePtr psTakeoffQueue, PriorityQueuePtr psLandingQueue,
									 bool *bEnd)
{
	bool bIsEmpty1, bIsEmpty2 = false;
	queueIsEmpty (psTakeoffQueue, &bIsEmpty1);
	pqueueIsEmpty (psLandingQueue, &bIsEmpty2);
	if (bIsEmpty1 && bIsEmpty2)
	{
		*bEnd = true;
	}
}

/****************************************************************************
 Function:      printStats

 Description:   prints the stats of the process

 Parameters:    none

 Returned:      none
****************************************************************************/
void printStats ()
{
	printf ("\n");
	printf ("Average takeoff wating time: %.5f\n", (gWaitTime / gTakeoffTotal));
	printf ("Average landing waiting time: %.3f\n", (gFlyingTime / gLandTotal));
	printf ("Average flying time remaining on landing: %.3f\n", (gTimeLeft / gLandTotal));
	printf ("Number of planes landing with zero fuel: %d\n", gNumEmergency);
	printf ("Number of crashes: %d\n\n", gCrashTotal);
}







