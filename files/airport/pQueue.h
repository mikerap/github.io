/*******************************************************************************
 File name:		  pQueue.h
 Author:        CS, Pacific University
 Date:          10/14/15
 Class:         CS300
 Assignment:    Priority Queue Implementation
 Purpose:       This file defines the constants, data structures, and function
                prototypes for implementing a priority queue data structure.
                In essence, the priority queue API is defined for other modules.
 ******************************************************************************/


#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <stdbool.h>
#include "../../DynamicList/include/list.h"

typedef short int PQ_ERRORCODE;

// Queue error codes for each function to use
#define PQ_NO_ERROR        				0

// Queue create failed
#define PQ_ERROR_NO_QUEUE_CREATE 	-1

// user tried to operate on an empty Queue
#define PQ_ERROR_EMPTY_QUEUE    	-2

// user tried to add data to a full Queue
#define PQ_ERROR_FULL_QUEUE       -3

// user tried to operate on an invalid Queue. An invalid
// Queue may be a NULL QueuePtr or contain an invalid List
#define PQ_ERROR_INVALID_QUEUE		-4

// user provided a NULL pointer to the function (other than the QueuePtr)
#define PQ_ERROR_NULL_PTR				 	-5


typedef struct PriorityQueue* PriorityQueuePtr;
typedef struct PriorityQueue
{
	List sTheList;
} PriorityQueue;

/******************************************************************************
*										Allocation and Deallocation
*****************************************************************************/
PQ_ERRORCODE pqueueCreate (PriorityQueuePtr psQueue);
// results: If psQueue can be created, then psQueue exists and
// is empty returning PQ_NO_ERROR; otherwise,
// PQ_ERROR_NO_QUEUE_CREATE is returned
// PQ_ERROR_INVALID_QUEUE is returned if psQueue is NULL


PQ_ERRORCODE pqueueTerminate (PriorityQueuePtr psQueue);
// results: psQueue no longer exists and returns PQ_NO_ERROR otherwise
// PQ_ERROR_INVALID_QUEUE is returned if psQueue is NULL

/******************************************************************************
*									Checking number of elements in queue
*****************************************************************************/
PQ_ERRORCODE pqueueSize (PriorityQueuePtr psQueue, int *pSize);
// results: Returns the number of elements in psQueue in the variable pointed
// to by pSize and returns PQ_NO_ERROR
// Possible errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_NULL_PTR if pSize is null

PQ_ERRORCODE pqueueIsEmpty (PriorityQueuePtr psQueue, bool *pbIsEmpty);
// results: If psQueue is empty, return true and PQ_NO_ERROR;
// otherwise, return false
// Possible errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_NULL_PTR if bool is null

PQ_ERRORCODE pqueueIsFull (PriorityQueuePtr psQueue, bool *pbIsFull);
// results: If psQueue is full, return true and PQ_NO_ERROR;
// otherwise, return false
// Possible errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_NULL_PTR if bool is null

/******************************************************************************
*									Inserting and retrieving values
*****************************************************************************/
PQ_ERRORCODE pqueueEnqueue (PriorityQueuePtr psQueue, Q_DATATYPE data);
// requires: psQueue is not full
// results: Insert the element into the priority queue based on the priority
//          of the element.
// Possible Errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_FULL_QUEUE if psQueue is full

PQ_ERRORCODE pqueueDequeue (PriorityQueuePtr psQueue, Q_DATATYPE *psData);
// requires: psQueue is not empty
// results: The front element is deleted and its successor becomes the front
// 					element. The deleted element is returned through the argument list.
// Possible Errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_NULL_PTR if psData is null
// PQ_ERROR_EMPTY_QUEUE if psQueue is empty

/******************************************************************************
*													Peek Operations
*****************************************************************************/
PQ_ERRORCODE pqueuePeek (PriorityQueuePtr psQueue, Q_DATATYPE *psData);
// requires: psQueue is not empty
// results: The value of the top element is
// returned through the argument list
// IMPORTANT: Do not remove element from the queue
// Possible Errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_NULL_PTR if psData is null
// PQ_ERROR_EMPTY_QUEUE if psQueue is empty

PQ_ERRORCODE pqueueChangePriority (PriorityQueuePtr psQueue, int change);
// requires: psQueue is not empty
// results: The priority of all elements is increased
// by the amount in change
// Possible Errors:
// PQ_ERROR_INVALID_QUEUE if psQueue is null
// PQ_ERROR_EMPTY_QUEUE if psQueue is empty


/******************************************************************************
*													Error Output Operations
*****************************************************************************/
const char* pqueueErrorString (PQ_ERRORCODE theError);
void printQError (PQ_ERRORCODE error);


#endif /* PQUEUE_H_ */

