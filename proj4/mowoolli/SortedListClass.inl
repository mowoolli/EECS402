#include <iostream>
using namespace std;
template < class T >
SortedListClass< T >::SortedListClass()
{
  
}

template < class T >
void SortedListClass< T >::clear()
{
  ListNodeClass< T > *temp = head;

  if (temp == NULL)
  {
    cout << "Can not delete from list!!" << endl;
  }
  else
  {
    while (head != NULL)
    {
      temp = head;
      head = temp->ListNodeClass< T >::getNext();
      delete temp;
      tail = NULL;
    }
  }  
}

template < class T >
void SortedListClass< T >::insertValue(const T &valToInsert)
{
  ListNodeClass< T > *newNodePtr;
  newNodePtr = new ListNodeClass< T >(NULL, valToInsert, NULL);

  ListNodeClass< T > *temp = newNodePtr->ListNodeClass< T >::getNext();

  int numOfElements = SortedListClass< T >::getNumElems();

  if (numOfElements == 0)
  {
    newNodePtr->ListNodeClass< T >::setPreviousPointer(newNodePtr);
    head = newNodePtr->ListNodeClass< T >::getPrev();
    newNodePtr->ListNodeClass< T >::setPreviousPointer(NULL);
    newNodePtr->ListNodeClass< T >::setNextPointer(newNodePtr);
    tail = newNodePtr->ListNodeClass< T >::getNext();
    newNodePtr->ListNodeClass< T >::setNextPointer(NULL);
  }
  else if (numOfElements == 1)
  {
    temp = head;
    
    if (newNodePtr->ListNodeClass< T >::getValue() < temp->ListNodeClass< T >::getValue())
    {
      newNodePtr->ListNodeClass< T >::setNextPointer(head);
      newNodePtr->ListNodeClass< T >::setPreviousPointer(newNodePtr);
      head = newNodePtr->ListNodeClass< T >::getPrev();
      newNodePtr->ListNodeClass< T >::setPreviousPointer(NULL);
      temp->ListNodeClass< T >::setPreviousPointer(newNodePtr);
    }
    else if (newNodePtr->ListNodeClass< T >::getValue() >= temp->ListNodeClass< T >::getValue())
    {
      newNodePtr->ListNodeClass< T >::setPreviousPointer(tail);
      newNodePtr->ListNodeClass< T >::setNextPointer(newNodePtr);
      tail = newNodePtr->ListNodeClass< T >::getNext();
      newNodePtr->ListNodeClass< T >::setNextPointer(NULL);
      temp->ListNodeClass< T >::setNextPointer(newNodePtr);
    }
  }
  else if (numOfElements >= 2)
  {
    if (newNodePtr->ListNodeClass< T >::getValue() < head->ListNodeClass< T >::getValue())
    {
      temp = head;
      newNodePtr->ListNodeClass< T >::setNextPointer(head);
      newNodePtr->ListNodeClass< T >::setPreviousPointer(newNodePtr);
      head = newNodePtr->ListNodeClass< T >::getPrev();
      newNodePtr->ListNodeClass< T >::setPreviousPointer(NULL);
      temp->ListNodeClass< T >::setPreviousPointer(newNodePtr);
    }
    else if (newNodePtr->ListNodeClass< T >::getValue() > tail->ListNodeClass< T >::getValue())
    {
      temp = tail;
      newNodePtr->ListNodeClass< T >::setPreviousPointer(tail);
      newNodePtr->ListNodeClass< T >::setNextPointer(newNodePtr);
      tail = newNodePtr->ListNodeClass< T >::getNext();
      newNodePtr->ListNodeClass< T >::setNextPointer(NULL);
      temp->ListNodeClass< T >::setNextPointer(newNodePtr);
    }
    else
    {
      temp = head;

      newNodePtr->ListNodeClass< T >::setNextPointer(newNodePtr);
      newNodePtr->ListNodeClass< T >::setPreviousPointer(newNodePtr);

      do
      {
        newNodePtr->ListNodeClass< T >::setPreviousPointer(temp);
        temp = temp->ListNodeClass< T >::getNext();
      } while (newNodePtr->ListNodeClass< T >::getValue() >= temp->ListNodeClass< T >::getValue());  

      newNodePtr->ListNodeClass< T >::setNextPointer(temp);
      newNodePtr->ListNodeClass< T >::setBeforeAndAfterPointers();
    }
  }
}

template < class T >
void SortedListClass< T >::printForward() const
{
  ListNodeClass< T > *temp = head;

  if (temp == NULL)
  {
    cout << "List is empty!" << endl;
  }
  else
  {
    cout << "Forward List Contents Follow:" << endl;
    while (temp != NULL)
    {
      cout << "  ";
      cout << temp->ListNodeClass< T >::getValue() << endl;
      temp = temp->ListNodeClass< T >::getNext();
      cout << endl;
    }
  }
}

template < class T >
void SortedListClass< T >::printBackward() const
{
  ListNodeClass< T > *temp = tail;

  if (temp == NULL)
  {
    cout << "List is empty!" << endl;
  }
  else
  {
    cout << "Backward List Contents Follow:" << endl;
    while (temp != NULL)
    {
      cout << "  ";
      cout << temp->ListNodeClass< T >::getValue() << endl;
      temp = temp->ListNodeClass< T >::getPrev();
      cout << endl;
    }
  }
}

template < class T >
bool SortedListClass< T >::removeFront(T &theVal)
{
  ListNodeClass< T > *temp;

  if (head == NULL)
  {
    cout << "Can not delete from list!" << endl;
    return (false);
  }
  else 
  {
    temp = head;
    head = temp->ListNodeClass< T >::getNext();
    theVal = temp->ListNodeClass< T >::getValue();
    delete temp;
    return (theVal);
  }

  return (true);
}

template < class T >
int SortedListClass< T >::getNumElems() const
{
  int emptyList = 0;
  int elemCounter = emptyList;

  ListNodeClass< T > *temp = head;

  if (temp == 0)
  {
    return (emptyList);
  }
  else
  {
    while (temp != NULL)
    {
      elemCounter++;
      temp = temp->ListNodeClass< T >::getNext();
    }

    return(elemCounter);
  }
}

template < class T >
bool SortedListClass< T >::getElemAtIndex(const int index,T &outVal)
{
  ListNodeClass< T > *temp = head;

  int numOfElements = SortedListClass< T >::getNumElems();

  if (temp == 0)
  {
    cout << "List is empty!" << endl;
    return (false);
  }
  else if (index < 0 || index > numOfElements)
  {
    cout << "Index is out of range!" << endl;
    return (false);
  }
  else
  {
    int listCounter = 0;

    while (listCounter != index)
    {
      temp = temp->ListNodeClass< T >::getNext();
      listCounter++;
    }
    
    outVal = temp->ListNodeClass< T >::getValue();
  
    return (true);
  }
}

