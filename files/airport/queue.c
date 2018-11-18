/*******************************************************************************
 File name:		  queue.c
 Author:        Mike Rapacon
 Date:          11/4/15
 Class:         CS300
 Assignment:    Queue Implementation
 Purpose:       This file implements the queue ADT
 ******************************************************************************/

#include "../include/queue.h"
#include "../../DynamicPriorityQ/include/pQueue.h"
#include "../../DynamicPriorityQ/src/pQueue.c"
#include <stdlib.h>
#include <stdbool.h>

/****************************************************************************
 Function:      queueCreate

 Description:   creates a Queue

 Parameters:    psQueue - pointer to a priority queue

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueCreate (QueuePtr psQueue)
{
	Q_ERRORCODE theError = NO_ERROR;
	if (psQueue)
	{
		pqueueCreate (&psQueue->sTheQueue);
	}
	else
	{
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
		else
		{
			theError = Q_ERROR_NO_QUEUE_CREATE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      ueueTerminate

 Description:   terminates a Queue

 Parameters:    psQueue - pointer to a priority queue

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueTerminate (QueuePtr psQueue)
{
	Q_ERRORCODE theError = NO_ERROR;
	if (psQueue)
	{
		pqueueTerminate (&psQueue->sTheQueue);
	}
	else
	{
		theError = Q_ERROR_INVALID_QUEUE;
	}
	return theError;
}

/****************************************************************************
 Function:      queueSize

 Description:   returns the number of elements in psQueue in the variable
 	 	 	 	 	 	 	 	pointed to by pSize

 Parameters:    psQueue - pointer to a priority queue
								pSize - pointer to an int containing the size

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueSize (QueuePtr psQueue, int *pSize)
{
	Q_ERRORCODE theError = NO_ERROR;
	if (psQueue && pSize)
	{
		pqueueSize (&psQueue->sTheQueue, pSize);
	}
	else
	{
		if (!pSize)
		{
			theError = Q_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      queueIsEmpty

 Description:   returns true if psQueue is empty, otherwise false

 Parameters:    psQueue - pointer to a priority queue
								pbIsEmpty - pointer to a bool

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueIsEmpty (QueuePtr psQueue, bool *pbIsEmpty)
{
	Q_ERRORCODE theError = NO_ERROR;
	if (psQueue && pbIsEmpty)
	{
		pqueueIsEmpty (&psQueue->sTheQueue, pbIsEmpty);
	}
	else
	{
		if (!pbIsEmpty)
		{
			theError = Q_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      queueIsFull

 Description:   returns true if psQueue is full, otherwise false

 Parameters:    psQueue - pointer to a priority queue
								pbIsEmpty - pointer to a bool

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueIsFull (QueuePtr psQueue, bool *pbIsFull)
{
	Q_ERRORCODE theError = NO_ERROR;
	if (psQueue && pbIsFull)
	{
		pqueueIsFull (&psQueue->sTheQueue, pbIsFull);
	}
	else
	{
		if (!pbIsFull)
		{
			theError = Q_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      queueEnqueue

 Description:   inserts the element into the priority queue based on the
 	 	 	 	 	 	 	 	priority of the element

 Parameters:    psQueue - pointer to a priority queue
								data - Q_DATATYPE to be inserted into the queue

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueEnqueue (QueuePtr psQueue, Q_DATATYPE data)
{
	Q_ERRORCODE theError = NO_ERROR;
	bool bIsFull = false;
	pqueueIsFull (&psQueue->sTheQueue, &bIsFull);
	if (psQueue && !bIsFull)
	{
		data.priority = 0;
		pqueueEnqueue (&psQueue->sTheQueue, data);
	}
	else
	{
		if (bIsFull)
		{
			theError = Q_ERROR_FULL_QUEUE;
		}
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      queueDequeue

 Description:   front element is deleted and its successor becomes the front
 	 	 	 	 	 	 	 	element. The deleted element is then returned through the
 	 	 	 	 	 	 	 	argument list.

 Parameters:    psQueue - pointer to a priority queue
								psData - pointer to a Q_DATATYPE

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queueDequeue (QueuePtr psQueue, Q_DATATYPE *psData)
{
	Q_ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	pqueueIsEmpty (&psQueue->sTheQueue, &bIsEmpty);
	if (psQueue && !bIsEmpty && psData)
	{
		pqueueDequeue (&psQueue->sTheQueue, psData);
	}
	else
	{
		if (bIsEmpty)
		{
			theError = Q_ERROR_EMPTY_QUEUE;
		}
		if (!psData)
		{
			theError = Q_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}

/****************************************************************************
 Function:      queuePeek

 Description:   returns the value of the top element

 Parameters:    psQueue - pointer to a priority queue
								*psData - pointer to Q_DATATYPE

 Returned:      Q_ERRORCODE
****************************************************************************/
Q_ERRORCODE queuePeek (QueuePtr psQueue, Q_DATATYPE *psData)
{
	Q_ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	pqueueIsEmpty (&psQueue->sTheQueue, &bIsEmpty);
	if (psQueue && !bIsEmpty && psData)
	{
		pqueuePeek (&psQueue->sTheQueue, psData);
	}
	else
	{
		if (bIsEmpty)
		{
			theError = Q_ERROR_EMPTY_QUEUE;
		}
		if (!psData)
		{
			theError = Q_ERROR_NULL_PTR;
		}
		if (!psQueue)
		{
			theError = Q_ERROR_INVALID_QUEUE;
		}
	}
	return theError;
}



