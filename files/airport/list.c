/*******************************************************************************
 File name:		  list.c
 Author:        Mike Rapacon
 Date:          10/12/15
 Class:         CS300
 Assignment:    Dynamic List
 Purpose:       This file defines the function implementation for a list data
 	 	 	 	 	 	 	 	structure.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/list.h"

/****************************************************************************
 Function: 	  lstCreate

 Description: creates a list defined as type struct

 Parameters:  psList - pointer to a stack

 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstCreate (ListPtr psList)
{
	ERRORCODE theError = NO_ERROR;
	if (psList != NULL)
	{
		psList->numElements = 0;
		psList->psHead = NULL;
		psList->psLast = NULL;
		psList->psCurrent = NULL;
	}
	else
	{
		theError = ERROR_NO_LIST_CREATE;
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstDispose

 Description: disposes of a list defined as type struct

 Parameters:  psList - pointer to a stack

 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstDispose (ListPtr psList)
{
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	ERRORCODE theError = NO_ERROR;
	if (psList && !bIsEmpty)
	{
		ListElementPtr psTemp = NULL;
   	psTemp = (ListElementPtr) malloc (sizeof (ListElement));
   	psList->psCurrent = psList->psHead;
   	if (psList->numElements == 1)
   	{
   		psList->psHead = NULL;
   		psList->numElements--;
   	}
    if (psList->numElements > 1 && psList->psCurrent)
   	{
   		while (psList->psCurrent->psNext)
   		{
   			psTemp = psList->psCurrent->psNext;
   			//free (psList->psCurrent);
   			psList->psCurrent = psTemp;
   			psList->numElements--;
   		}
   	}
	}
	else
	{
		if (!psList)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (bIsEmpty)
		{
   		theError = ERROR_EMPTY_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstIsFull

 Description: determines if a list is full

 Parameters:  psList - pointer to a stack
							pbIsFull - pointer to a bool, true if stack is full
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstIsFull (ListPtr psList, bool *pbIsFull)
{
	ERRORCODE theError = NO_ERROR;
	if (psList != NULL && pbIsFull != NULL)
	{
		*pbIsFull = false;
	}
	else
	{
		if (pbIsFull == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstIsEmpty

 Description: determines if a list is empty

 Parameters:  psList - pointer to a stack
							pbIsEmpty - pointer to a bool, true is list is empty
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstIsEmpty (ListPtr psList, bool *pbIsEmpty)
{
	ERRORCODE theError = NO_ERROR;
	if (psList != NULL && pbIsEmpty != NULL)
	{
		if (psList->numElements <= 0)
		{
			*pbIsEmpty = true;
		}
		else
		{
			*pbIsEmpty = false;
		}
	}
	else
	{
		if (pbIsEmpty == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstFirst

 Description: returns the value of the first element in the list

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstFirst (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList && psData && !bIsEmpty && psList->psHead)
	{
		*psData = psList->psHead->data;
		psList->psCurrent = psList->psHead;
	}
	else
	{
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;

		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (!psList)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstInsertAfter

 Description: inserts the new element as the successor of the current element
							and makes the inserted element the current element
 Parameters:  psList - pointer to a stack
							data - DATATYPE to be inserted in the array
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstInsertAfter (ListPtr psList, DATATYPE data)
{
	ERRORCODE theError = NO_ERROR;
	ListElementPtr psElement;
	bool bIsEmpty;
	if (psList)
	{
		psElement = (ListElementPtr) malloc (sizeof (ListElement));
		psElement->data = data;
		psElement->psNext = NULL;
		lstIsEmpty (psList, &bIsEmpty);
		if (!bIsEmpty && psList->psCurrent)
		{
			psElement->psNext = psList->psCurrent->psNext;
			psList->psCurrent->psNext = psElement;
			psList->psCurrent = psElement;
			if (psElement->psNext == NULL)
			{
				psList->psLast = psElement;
			}
		}
		else
		{
			if (!psList->psCurrent)
			{
				psList->psCurrent = psList->psLast;
			}
			psList->psHead = psList->psLast = psList->psCurrent = psElement;
		}
		psList->numElements++;
	}
	else
	{
		theError = ERROR_INVALID_LIST;
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstNext

 Description: value of the current element is returned

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstNext (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList && psData && !bIsEmpty && psList->psCurrent)
	{
		*psData = psList->psCurrent->data;
		if (psList->psCurrent->psNext)
		{
			psList->psCurrent = psList->psCurrent->psNext;
		}
	}
	else
	{
		if (psData)
		{
			theError = ERROR_NULL_PTR;
		}
		if (psList)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (!psList->psCurrent)
		{
			theError = ERROR_NO_CURRENT;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstSize

 Description: returns the number of elements in the list

 Parameters:  psList - pointer to a stack
							pSize - pointer to an int
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstSize (ListPtr psList, int *pSize)
{
	ERRORCODE theError = NO_ERROR;
	if (psList && pSize)
	{
		*pSize = psList->numElements;
	}
	else
	{
		if (pSize == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstPeek

 Description: value of the current element is returned

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstPeek (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList != NULL && psData != NULL && !bIsEmpty && psList->psCurrent)
	{
		*psData = psList->psCurrent->data;
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
			if (psList->psCurrent == NULL)
			{
				theError = ERROR_NO_CURRENT;
			}
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstPeekPrev

 Description: data value of current's predecessor is returned

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstPeekPrev (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList != NULL && psData != NULL && !bIsEmpty &&
			psList->psCurrent != psList->psHead)
	{
		ListElementPtr psTemp = psList->psHead;
		while (psTemp != psList->psCurrent)
		{
			if (psTemp->psNext == psList->psCurrent)
			{
				*psData = psTemp->data;
			}
			psTemp = psTemp->psNext;
		}
	}
	else
	{
		if (psList->psCurrent->psPrev == NULL)
		{
			theError = ERROR_NO_PREV;
		}
		if (psList->psCurrent == NULL)
		{
			theError = ERROR_NO_CURRENT;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstPeekNext

 Description: data value of current's successor is returned

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstPeekNext (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList != NULL && psData != NULL && !bIsEmpty &&
			psList->psCurrent->psNext)
	{
		*psData = psList->psCurrent->psNext->data;
	}
	else
	{
		if (psList->psCurrent->psNext == NULL)
		{
			theError = ERROR_NO_NEXT;
		}
		if (psList->psCurrent == NULL)
		{
			theError = ERROR_NO_CURRENT;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstLast

 Description: value of the last element is returned

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstLast (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList != NULL && psData != NULL && !bIsEmpty && psList->psLast)
	{
		*psData = psList->psLast->data;
		psList->psCurrent = psList->psLast;
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstPrev

 Description: value of the current element is returned

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstPrev (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList != NULL && psData != NULL && !bIsEmpty)
	{
		*psData = psList->psCurrent->data;
		if (psList->psCurrent->psPrev)
		{
			psList->psCurrent = psList->psCurrent->psPrev;
		}
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstDeleteCurrent

 Description: current element is deleted and its successor and predecessor
 	 	 	 	 	 	  are linked

 Parameters:  psList - pointer to a stack
							psData - pointer to a DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstDeleteCurrent (ListPtr psList, DATATYPE *psData)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty = false;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList != NULL && psData != NULL && !bIsEmpty && psList->psCurrent)
	{
		ListElementPtr psElement;
		*psData = psList->psCurrent->data;
		psElement = psList->psCurrent;
		if (psElement != psList->psHead)
		{
			psList->psCurrent = psElement->psPrev = psElement->psNext;
		}
		else
		{
			psList->psCurrent = psList->psHead = psElement->psNext;
		}
		psList->numElements--;
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (psData == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstInsertBefore

 Description: insert new element as the predecessor of the current element
 	 	 	 	 	 	  and make the new element the current element

 Parameters:  psList - pointer to a stack
							data -  DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstInsertBefore (ListPtr psList, DATATYPE data)
{
	ERRORCODE theError = NO_ERROR;
	ListElementPtr psElement;
	DATATYPE temp;
	bool bIsEmpty;
	if (psList != NULL)
	{
		psElement = (ListElementPtr) malloc (sizeof (ListElement));
		lstIsEmpty (psList, &bIsEmpty);
		if (!bIsEmpty)
		{
			temp = psList->psCurrent->data;
			psElement = psList->psCurrent;
			psList->psCurrent->data = data;
			lstInsertAfter (psList, temp);
		}
		else
		{
			psList->psHead = psList->psLast = psList->psCurrent = psElement;
			psList->numElements++;
		}
	}
	else
	{
		theError = ERROR_INVALID_LIST;
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstUpdateCurrent

 Description: value of ListElement is copied into the current element

 Parameters:  psList - pointer to a stack
							data - DATATYPE
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstUpdateCurrent (ListPtr psList, DATATYPE data)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList && !bIsEmpty)
	{
		psList->psCurrent->data = data;
	}
	else
	{
		if (!psList->psCurrent)
		{
			theError = ERROR_NO_CURRENT;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (!psList)
		{
			theError = ERROR_INVALID_LIST;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstHasCurrent

 Description: returns true if the current node is not NULL

 Parameters:  psList - pointer to a stack
							pbHasCurr - pointer to a bool
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstHasCurrent (ListPtr psList, bool *pbHasCurr)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList && !bIsEmpty && pbHasCurr != NULL && psList->psCurrent)
	{
		if (psList->psCurrent != NULL)
		{
			*pbHasCurr = true;
		}
		else
		{
			*pbHasCurr = false;
		}
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
			if (psList->psCurrent == NULL)
			{
				theError = ERROR_NO_CURRENT;
			}
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (pbHasCurr == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstHasNext

 Description: returns true if the current node has a successor

 Parameters:  psList - pointer to a stack
							pbHasNext - pointer to a bool
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstHasNext (ListPtr psList, bool *pbHasNext)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList && !bIsEmpty && pbHasNext != NULL && psList->psCurrent)
	{
		if (psList->psCurrent->psNext)
		{
			*pbHasNext = true;
		}
		else
		{
			*pbHasNext = false;
		}
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (psList->psCurrent == NULL)
		{
			theError = ERROR_NO_CURRENT;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (pbHasNext == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
	}
	return theError;
}

/****************************************************************************
 Function: 	  lstHasPrev

 Description: returns true if the current node has a predecessor

 Parameters:  psList - pointer to a stack
							pbHasPrev - pointer to a bool
 Returned:    ERRORCODE
 ****************************************************************************/
ERRORCODE lstHasPrev (ListPtr psList, bool *pbHasPrev)
{
	ERRORCODE theError = NO_ERROR;
	bool bIsEmpty;
	lstIsEmpty (psList, &bIsEmpty);
	if (psList && !bIsEmpty && pbHasPrev != NULL && psList->psCurrent)
	{
		if (psList->psCurrent->psPrev != NULL)
		{
			*pbHasPrev = true;
		}
		else
		{
			*pbHasPrev = false;
		}
	}
	else
	{
		if (psList == NULL)
		{
			theError = ERROR_INVALID_LIST;
		}
		if (psList->psCurrent == NULL)
		{
			theError = ERROR_NO_CURRENT;
		}
		if (bIsEmpty)
		{
			theError = ERROR_EMPTY_LIST;
		}
		if (pbHasPrev == NULL)
		{
			theError = ERROR_NULL_PTR;
		}
	}
	return theError;
}
