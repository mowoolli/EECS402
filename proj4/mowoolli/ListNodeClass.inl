#include <iostream>
using namespace std;
template < class T >
ListNodeClass< T >::ListNodeClass(ListNodeClass *inPrev, const T &inVal,
                             ListNodeClass *inNext)
{
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
}

template < class T >
void ListNodeClass< T >::setNextPointer(ListNodeClass *newNextPtr)
{
  nextNode = newNextPtr;
}

template < class T >
T ListNodeClass< T >::getValue() const
{
  return (nodeVal);
}

template < class T >
ListNodeClass< T >* ListNodeClass< T >::getNext() const
{
  return (nextNode);
}

template < class T >
ListNodeClass< T >* ListNodeClass< T >::getPrev() const
{
  return (prevNode);
}

template < class T >
void ListNodeClass< T >::setPreviousPointer(ListNodeClass *newPrevPtr)
{
  prevNode = newPrevPtr;
}

template < class T >
void ListNodeClass< T >::setBeforeAndAfterPointers()
{
  nextNode->prevNode = this;
  prevNode->nextNode = this;
}
