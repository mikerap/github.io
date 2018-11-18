/*******************************************************************************
 File name:		  list.h
 Author:        CS, Pacific University
 Date:          10/1/15
 Class:         CS300
 Assignment:    List Implementation
 Purpose:       This file defines the constants, data structures, and function
                prototypes for implementing a list data structure. In essence,
                the list API is defined for other modules. This list has been
                modified for the Priority Queue assignment.
 ******************************************************************************/

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

// List error codes for each function to use

#define NO_ERROR        				0

// list create failed
#define ERROR_NO_LIST_CREATE 	 -1

// user tried to operate on an empty list
#define ERROR_EMPTY_LIST     	 -2

// user tried to add data to a full list
#define ERROR_FULL_LIST        -3

// user tried to peekNext when no next existed
#define ERROR_NO_NEXT          -4

// user tried to peekPrev when no prev existed
#define ERROR_NO_PREV          -5

// user tried to use current when current is NULL
#define ERROR_NO_CURRENT			 -6

// user tried to operate on an invalid list. An invalid
// list may be a NULL ListPtr or contain an invalid value for numElements
#define ERROR_INVALID_LIST		 -7

// user provided a NULL pointer to the function (other than the ListPtr)
#define ERROR_NULL_PTR				 -8

// Possible datatypes for later use
#define CHARACTER_VALUE 0
#define INTEGER_VALUE   1
#define FLOAT_VALUE     2

typedef short int ERRORCODE;

// The user of this data structure is only concerned with
// two data types: List and DATATYPE.  ListElement is an internal
// data structure not to be directly used by the user.
// If the List implementation changes (to static memory, a tree, etc)
// ListElement will change.

// Added for priority queue module. Do not use for list assignment.
typedef struct Q_DATATYPE
{
	int intValue;
	int priority;
}Q_DATATYPE;

typedef struct DATATYPE
{
	Q_DATATYPE data; // Do not use for list assignment

	// maintained so that the list driver still works with list
	union
  {
  	char charValue;
  	unsigned int intValue;
    float floatValue;
  };
  unsigned short whichOne;
} DATATYPE;

typedef struct ListElement* ListElementPtr;
typedef struct ListElement
{
	DATATYPE data;
	ListElementPtr psNext;
	ListElementPtr psPrev;
} ListElement;


// A list is a dynamic data structure where the current pointer and number
// of elements are maintained at all times

typedef struct List* ListPtr;
typedef struct List
{
	ListElementPtr psHead;
	ListElementPtr psLast;
	ListElementPtr psCurrent;
	int numElements;
} List;

/******************************************************************************
*										Allocation and Deallocation
*****************************************************************************/
ERRORCODE lstCreate (ListPtr psList);
// results: If list L can be created, then L exists and is empty returning
//					NO_ERROR; otherwise, ERROR_NO_LIST_CREATE is returned

ERRORCODE lstDispose (ListPtr psList);
// results: If list L can be disposed, then L no longer exists and is empty
//				  returning NO_ERROR; otherwise, ERROR_INVALID_LIST is returned

/******************************************************************************
*									Checking number of elements in list
*****************************************************************************/
ERRORCODE lstSize (ListPtr psList, int *pSize);
// results: Returns the number of elements in the list
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR

ERRORCODE lstIsFull (ListPtr psList, bool *pbIsFull);
// results: If list is full, return true; otherwise, return false
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR

ERRORCODE lstIsEmpty (ListPtr psList, bool *pbIsEmpty);
// results: If list is empty, return true; otherwise, return false
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR

/******************************************************************************
*													Peek Operations
*****************************************************************************/
ERRORCODE lstPeek (ListPtr psList, DATATYPE *psData);
// requires: List is not empty
// results: The value of the current element is returned
// IMPORTANT: Do not change current
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST,
//											ERROR_NO_CURRENT

ERRORCODE lstPeekPrev (ListPtr psList, DATATYPE *psData);
// requires: List contains two or more elements and current is not the first
// results: The data value of current's predecessor is returned
// IMPORTANT: Do not change current
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST,
//											ERROR_NO_CURRENT, ERROR_NO_PREV

ERRORCODE lstPeekNext (ListPtr psList, DATATYPE *psData);
// requires: List contains two or more elements and current is not the last
// results: The data value of current's successor is returned
// IMPORTANT: Do not change current
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST,
//											ERROR_NO_CURRENT, ERROR_NO_NEXT

/******************************************************************************
*							Retrieving values and updating current
*****************************************************************************/
ERRORCODE lstFirst(ListPtr psList, DATATYPE *psData);
// requires: List is not empty
// results: The value of the first element is returned
// IMPORTANT: Current is changed to first if it exists
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST

 ERRORCODE lstLast(ListPtr psList, DATATYPE *psData);
// requires: List is not empty
// results: The value of the last element is returned
// IMPORTANT: Current is changed to last if it exists
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST

 ERRORCODE lstNext(ListPtr psList, DATATYPE *psData);
// requires: List is not empty, and current is not NULL
// results: The value of the current element is returned
// IMPORTANT: Current is changed to the successor of the current element
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST,
//											ERROR_NO_CURRENT

ERRORCODE lstPrev(ListPtr psList, DATATYPE *psData);
// requires: List is not empty, and current is not NULL
// results: The value of the current element is returned
// IMPORTANT: Current is changed to previous if it exists
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST
//											ERROR_NO_CURRENT

/******************************************************************************
*									Insertion, Deletion, and Updating
*****************************************************************************/
ERRORCODE lstDeleteCurrent (ListPtr psList, DATATYPE *psData);
// requires: List is not empty
// results: The current element is deleted and its
// successor and predecessor become each
// others successor and predecessor. If the
// deleted element had a predecessor, then
// make it the new current element; otherwise,
// make the first element current if it exists.
// The deleted element is returned through the argument list.
// error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST
//											ERROR_NO_CURRENT

 ERRORCODE lstInsertAfter (ListPtr psList, DATATYPE data);
// requires: List is not full
// results: if the list is not empty, insert the new
// element as the successor of the current
// element and make the inserted element the
// current element; otherwise, insert element
// and make it current.
// error code priority: ERROR_INVALID_LIST, ERROR_NO_CURRENT

 ERRORCODE lstInsertBefore (ListPtr psList, DATATYPE data);
// requires: List is not full
// results: If the list is not empty, insert the new
// element as the predecessor of the current
// element and make the inserted element the
// current element; otherwise, insert element
// and make it current.
// error code priority: ERROR_INVALID_LIST, ERROR_NO_CURRENT

 ERRORCODE lstUpdateCurrent (ListPtr psList, DATATYPE data);
// requires: List is not empty
// results: The value of ListElement is copied into the current element
// error code priority: ERROR_INVALID_LIST, ERROR_EMPTY_LIST, ERROR_NO_CURRENT

/******************************************************************************
*												List Testing
*****************************************************************************/

 ERRORCODE lstHasCurrent (ListPtr psList, bool *pbHasCurr);
 // results: Returns true if the current node is not NULL; otherwise, false
 //					 is returned
 // error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST
 //											ERROR_NO_CURRENT

ERRORCODE lstHasNext (ListPtr psList, bool *pbHasNext);
 // results: Returns true if the current node has a successor; otherwise, false
 //					 is returned
 // error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST
 //											ERROR_NO_CURRENT

 ERRORCODE lstHasPrev(ListPtr psList, bool *pbHasPrev);
 // results: Returns true if the current node has a predecessor; otherwise,
 //					 false is returned
 // error code priority: ERROR_INVALID_LIST, ERROR_NULL_PTR, ERROR_EMPTY_LIST
 //											ERROR_NO_CURRENT

#endif /* LIST_H_ */
