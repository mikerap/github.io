/*******************************************************************************
 File name:		  queue.h
 Author:        CS, Pacific University
 Date:          10/28/15
 Class:         CS300
 Assignment:    Queue Header File
 Purpose:       This file defines the constants, data structures, and function
                prototypes for implementing a queue data structure.
                In essence, the queue API is defined for other modules.
 ******************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include "../../DynamicPriorityQ/include/pQueue.h"

typedef short int Q_ERRORCODE;

// Queue error codes for each function to use
#define Q_NO_ERROR        			0

// Queue create failed
#define Q_ERROR_NO_QUEUE_CREATE 	-1

// user tried to operate on an empty Queue
#define Q_ERROR_EMPTY_QUEUE    	 	-2

// user tried to add data to a full Queue
#define Q_ERROR_FULL_QUEUE        -3

// user tried to operate on an invalid Queue. An invalid
// Queue may be a NULL QueuePtr or contain an invalid List
#define Q_ERROR_INVALID_QUEUE		 -4

// user provided a NULL pointer to the function (other than the QueuePtr)
#define Q_ERROR_NULL_PTR				 -5


typedef struct Queue* QueuePtr;
typedef struct Queue
{
	PriorityQueue sTheQueue;
} Queue;

/******************************************************************************
*										Allocation and Deallocation
*****************************************************************************/
Q_ERRORCODE queueCreate (QueuePtr psQueue);
// results: If Queue can be created, then Queue exists and
// is empty returning Q_NO_ERROR; otherwise,
// Q_ERROR_NO_QUEUE_CREATE is returned


Q_ERRORCODE queueTerminate (QueuePtr psQueue);
// results: Queue no longer exists
// Q_ERROR_INVALID_QUEUE

/******************************************************************************
*									Checking number of elements in queue
*****************************************************************************/
Q_ERRORCODE queueSize (QueuePtr psQueue, int *pSize);
// results: Returns the number of elements in the Queue
// Possible errors:
// Q_ERROR_INVALID_QUEUE
// Q_ERROR_NULL_PTR

Q_ERRORCODE queueIsEmpty (QueuePtr psQueue, bool *pbIsEmpty);
// results: If queue is empty, return true;
// otherwise, return false
// Possible errors:
// Q_ERROR_INVALID_QUEUE
// Q_ERROR_NULL_PTR

Q_ERRORCODE queueIsFull (QueuePtr psQueue, bool *pbIsFull);
// results: If queue is full, return true; otherwise, return false
// Possible errors:
// PQ_ERROR_INVALID_QUEUE
// PQ_ERROR_NULL_PTR

/******************************************************************************
*									Inserting and retrieving values
*****************************************************************************/
Q_ERRORCODE queueEnqueue (QueuePtr psQueue, Q_DATATYPE data);
// requires: Queue is not full
// results: Insert the element at the back of the queue
// Possible Errors:
// Q_ERROR_INVALID_QUEUE
// Q_ERROR_FULL_QUEUE

Q_ERRORCODE queueDequeue (QueuePtr psQueue, Q_DATATYPE *psData);
// requires: Queue is not empty
// results: The top element is deleted and its
// predecessor becomes the top element.
// The deleted element is returned through the argument
// list.
// Possible Errors:
// Q_ERROR_INVALID_QUEUE
// Q_ERROR_NULL_PTR
// Q_ERROR_EMPTY_LIST

/******************************************************************************
*													Peek Operations
*****************************************************************************/
Q_ERRORCODE queuePeek (QueuePtr psQueue, Q_DATATYPE *psData);
// requires: Queue is not empty
// results: The value of the top element is
// returned through the argument list
// IMPORTANT: Do not remove element from the queue
// Possible Errors:
// 	Q_ERROR_INVALID_QUEUE
//	Q_ERROR_NULL_PTR
//	Q_ERROR_EMPTY_QUEUE


/******************************************************************************
*													Error Output Operations
*****************************************************************************/
const char* queueErrorString(Q_ERRORCODE theError);

#endif /* QUEUE_H_ */
