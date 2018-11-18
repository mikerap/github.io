/*******************************************************************************
 File name:		  pQueue.c
 Author:        CS, Pacific University
 Date:          10/10/14
 Class:         CS300
 Assignment:    Priority Queue Implementation
 Purpose:       This file implements the priority queue ADT
 ******************************************************************************/

#include "../include/pQueue.h"
#include "../../DynamicList/include/list.h"
#include "../../DynamicList/src/list.c"
#include <stdlib.h>
#include <stdbool.h>

static const char * ERRORMSGS[] =
{
	"NO ERROR",
	"NO PQUEUE CREATE",
	"EMPTY PQUEUE",
	"FULL PQUEUE",
	"INVALID PQUEUE",
	"NULL PTR"
};

/****************************************************************************
 Function:      pqueueCreate

 Description:   creates a PriorityQueue

 Parameters:    psQueue - pointer to a priority queue

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueCreate (PriorityQueuePtr psQueue)
{
	PQ_ERRORCODE theError = NO_ERROR;
	if (psQueue)
	{
		lstCreate (&psQueue->sTheList);
	}
	else
	{
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
		else
		{
			theError = PQ_ERROR_NO_QUEUE_CREATE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueTerminate

 Description:   terminates a PriorityQueue

 Parameters:    psQueue - pointer to a priority queue

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueTerminate (PriorityQueuePtr psQueue)
{
	PQ_ERRORCODE theError = NO_ERROR;
	if (psQueue)
	{
		lstDispose (&psQueue->sTheList);
	}
	else
	{
		theError = PQ_ERROR_INVALID_QUEUE;
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueSize

 Description:   returns the number of elements in psQueue in the variable
 	 	 	 	 	 	 	 	pointed to by pSize

 Parameters:    psQueue - pointer to a priority queue
								pSize - pointer to an int containing the size

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueSize (PriorityQueuePtr psQueue, int *pSize)
{
	PQ_ERRORCODE theError = NO_ERROR;
	if (psQueue && pSize)
	{
		lstSize (&psQueue->sTheList, pSize);
	}
	else
	{
		if (!pSize)
		{
			theError = PQ_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueIsEmpty

 Description:   returns true if psQueue is empty, otherwise false

 Parameters:    psQueue - pointer to a priority queue
								pbIsEmpty - pointer to a bool

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueIsEmpty (PriorityQueuePtr psQueue, bool *pbIsEmpty)
{
	PQ_ERRORCODE theError = NO_ERROR;
	if (psQueue && pbIsEmpty)
	{
		lstIsEmpty (&psQueue->sTheList, pbIsEmpty);
	}
	else
	{
		if (!pbIsEmpty)
		{
			theError = PQ_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueIsFull

 Description:   returns true if psQueue is full, otherwise false

 Parameters:    psQueue - pointer to a priority queue
								pbIsEmpty - pointer to a bool

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueIsFull (PriorityQueuePtr psQueue, bool *pbIsFull)
{
	PQ_ERRORCODE theError = NO_ERROR;
	if (psQueue && pbIsFull)
	{
		lstIsFull (&psQueue->sTheList, pbIsFull);
	}
	else
	{
		if (!pbIsFull)
		{
			theError = PQ_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueEnqueue

 Description:   inserts the element into the priority queue based on the
 	 	 	 	 	 	 	 	priority of the element

 Parameters:    psQueue - pointer to a priority queue
								data - Q_DATATYPE to be inserted into the queue

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueEnqueue (PriorityQueuePtr psQueue, Q_DATATYPE data)
{
	PQ_ERRORCODE theError = NO_ERROR;
	DATATYPE tempData;
	DATATYPE peekData;
	tempData.data = data;
	tempData.intValue = data.intValue;
	bool bIsFull, bHasNext, bIsEmpty = false;
	pqueueIsFull (psQueue, &bIsFull);
	pqueueIsEmpty (psQueue, &bIsEmpty);
	if (psQueue && !bIsFull)
	{
		if (bIsEmpty)
		{
			lstInsertAfter (&psQueue->sTheList, tempData);
		}
		else
		{
			lstFirst (&psQueue->sTheList, &peekData);
			if (peekData.data.priority >= data.priority)
			{
				lstInsertBefore (&psQueue->sTheList, tempData);
			}
			else
			{
				while (peekData.data.priority < data.priority)
				{
					lstHasNext (&psQueue->sTheList, &bHasNext);
					lstNext (&psQueue->sTheList, &peekData);
					if (!bHasNext && peekData.data.priority > data.priority)
					{
						lstInsertBefore (&psQueue->sTheList, tempData);
						break;
					}
					if (peekData.data.priority < data.priority)
					{
						lstInsertAfter (&psQueue->sTheList, tempData);
						break;
					}
					if (!bHasNext && peekData.data.priority > data.priority)
					{
						lstInsertAfter (&psQueue->sTheList, tempData);
						break;
					}
					lstNext (&psQueue->sTheList, &peekData);
				}
			}
		}
	}
	else
	{
		if (bIsFull)
		{
			theError = PQ_ERROR_FULL_QUEUE;
		}
		else if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueDequeue

 Description:   front element is deleted and its successor becomes the front
 	 	 	 	 	 	 	 	element. The deleted element is then returned through the
 	 	 	 	 	 	 	 	argument list.

 Parameters:    psQueue - pointer to a priority queue
								psData - pointer to a Q_DATATYPE

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueDequeue (PriorityQueuePtr psQueue, Q_DATATYPE *psData)
{
	PQ_ERRORCODE theError = NO_ERROR;
	DATATYPE data;
	bool bIsEmpty = false;
	pqueueIsEmpty (psQueue, &bIsEmpty);
	if (psQueue && !bIsEmpty && psData)
	{
		data.data = *psData;
		lstFirst (&psQueue->sTheList, &data);
		lstDeleteCurrent (&psQueue->sTheList, &data);
		*psData = data.data;
	}
	else
	{
		if (bIsEmpty)
		{
			theError = PQ_ERROR_EMPTY_QUEUE;
		}
		if (!psData)
		{
			theError = PQ_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueuePeek

 Description:   returns the value of the top element

 Parameters:    psQueue - pointer to a priority queue
								*psData - pointer to Q_DATATYPE

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueuePeek (PriorityQueuePtr psQueue, Q_DATATYPE *psData)
{
	PQ_ERRORCODE theError = NO_ERROR;
	DATATYPE data;
	bool bIsEmpty = false;
	lstIsEmpty (&psQueue->sTheList, &bIsEmpty);
	if (psQueue && !bIsEmpty && psData)
	{
		lstFirst (&psQueue->sTheList, &data);
		*psData = data.data;
	}
	else
	{
		if (bIsEmpty)
		{
			theError = PQ_ERROR_EMPTY_QUEUE;
		}
		if (!psData)
		{
			theError = PQ_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueChangePriority

 Description:   priority of all elements is increased by amount in change

 Parameters:    psQueue - pointer to a priority queue
								change - int containing amount to increase priority by

 Returned:      PQ_ERRORCODE
****************************************************************************/
PQ_ERRORCODE pqueueChangePriority (PriorityQueuePtr psQueue, int change)
{
	PQ_ERRORCODE theError = NO_ERROR;
	DATATYPE data;
	bool bIsEmpty;
	int size, i;
	pqueueIsEmpty (psQueue, &bIsEmpty);
	if (psQueue && !bIsEmpty)
	{
		pqueueSize (psQueue, &size);
		lstFirst (&psQueue->sTheList, &data);
		for (i = 0; i < size; i++)
		{
			lstPeek (&psQueue->sTheList, &data);
			data.data.priority += change;
			lstUpdateCurrent (&psQueue->sTheList, data);
			lstNext (&psQueue->sTheList, &data);
		}
	}
	else
	{
		if (bIsEmpty)
		{
			theError = PQ_ERROR_EMPTY_QUEUE;
		}
		if (!psQueue)
		{
			theError = PQ_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      pqueueErrorString

 Description:   makes the error code a pointer to chars

 Parameters:    PQ_ERRORCODE  - The error code that is to be printed.

 Returned:      pString       - the message that is to be outputed.
****************************************************************************/

const char* pqueueErrorString (PQ_ERRORCODE theError)
{
	const char* pString;

	switch (theError)
	{
		case PQ_NO_ERROR:
			pString = ERRORMSGS[0];
			break;
		case PQ_ERROR_NO_QUEUE_CREATE:
			pString = ERRORMSGS[1];
			break;
		case PQ_ERROR_EMPTY_QUEUE:
			pString = ERRORMSGS[2];
			break;
		case PQ_ERROR_FULL_QUEUE:
			pString = ERRORMSGS[3];
			break;
		case PQ_ERROR_INVALID_QUEUE:
			pString = ERRORMSGS[4];
			break;
		case PQ_ERROR_NULL_PTR:
			pString = ERRORMSGS[5];
			break;
		default:
			pString = ERRORMSGS[0];
			break;
	}
	return pString;
}

void printQError (PQ_ERRORCODE error)
{
	switch (error)
	{
		case PQ_NO_ERROR:
			printf ("Results: (NO ERROR)\n");
			break;
		case PQ_ERROR_NO_QUEUE_CREATE:
			printf ("Results: (ERROR: NO QUEUE CREATE)\n");
			break;
		case PQ_ERROR_EMPTY_QUEUE:
			printf ("Results: (ERROR: EMPTY QUEUE)\n");
			break;
		case PQ_ERROR_FULL_QUEUE:
			printf ("Results: (ERROR: FULL QUEUE)\n");
			break;
		case PQ_ERROR_INVALID_QUEUE:
			printf ("Results: (ERROR: INVALID QUEUE)\n");
			break;
		case PQ_ERROR_NULL_PTR:
			printf ("Results: (ERROR: NULL POINTER)\n");
			break;
	}
}

