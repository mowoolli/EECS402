#include <iostream>
using namespace std;
template < class T >
QueueClass< T >::QueueClass()
{

}

template < class T >
int QueueClass< T >::sizeOfQueue()
{
  int emptyQueue = 0;
  int queueCounter = emptyQueue;

  ListNodeClass< T > *temp = front;

  if (temp == 0)
  {
    return (emptyQueue);
  }
  else
  {
    while (temp != NULL)
    {
      queueCounter++;
      temp = temp->ListNodeClass< T >::getNext();
    }

    return(queueCounter);
  }
}

template < class T >
void QueueClass< T >::enqueue(const T &enqueueVal)
{
  ListNodeClass< T > *newQueueNodePtr;
  newQueueNodePtr = new ListNodeClass< T >(NULL, enqueueVal, NULL);

  ListNodeClass< T > *temp = newQueueNodePtr->ListNodeClass< T >::getNext();

  int numInQueue = QueueClass< T >::sizeOfQueue();
  
  if (numInQueue == 0)
  {
    newQueueNodePtr->ListNodeClass< T >::setPreviousPointer(newQueueNodePtr);
    front = newQueueNodePtr->ListNodeClass< T >::getPrev();
    newQueueNodePtr->ListNodeClass< T >::setPreviousPointer(NULL);
    newQueueNodePtr->ListNodeClass< T >::setNextPointer(newQueueNodePtr);
    back = newQueueNodePtr->ListNodeClass< T >::getNext();
    newQueueNodePtr->ListNodeClass< T >::setNextPointer(NULL);
  }
  else
  {
    temp = back;
    newQueueNodePtr->ListNodeClass< T >::setPreviousPointer(back);
    newQueueNodePtr->ListNodeClass< T >::setNextPointer(newQueueNodePtr);
    back = newQueueNodePtr->ListNodeClass< T >::getNext();
    newQueueNodePtr->ListNodeClass< T >::setNextPointer(NULL);
    temp->ListNodeClass< T >::setNextPointer(newQueueNodePtr);
  }
}

template < class T >
void QueueClass< T >::dequeue()
{
  ListNodeClass< T > *temp = front;

  int numInQueue = QueueClass< T >::sizeOfQueue();

  if (numInQueue == 1)
  {
    front = NULL;
    back = NULL;
  }
  else
  {
    front = front->ListNodeClass< T >::getNext();
    front->ListNodeClass< T >::setPreviousPointer(front);
    front->ListNodeClass< T >::setPreviousPointer(NULL);
    temp->ListNodeClass< T >::setNextPointer(NULL);
    delete temp;
  }
}

template < class T >
void QueueClass< T >::printQueue()
{
  ListNodeClass< T > *temp = front;

  if (front == NULL)
  {
    cout << "List is empty!" << endl;
  }
  else
  {
    cout << "Forward Queue Contents Follow:" << endl;
    while (temp != NULL)
    {
      cout << "  ";
      cout << temp->ListNodeClass< T >::getValue() << endl;
      temp = temp->ListNodeClass< T >::getNext();
      cout << endl;
    }
  }
}


