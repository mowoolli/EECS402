#ifndef QUEUE_TEMPLATE_H_
#define QUEUE_TEMPLATE_H_
template < class T >
class QueueClass
{
  private:
    ListNodeClass< T > *front;
    ListNodeClass< T > *back;

  public:
    QueueClass( // Default ctor
        );

    int sizeOfQueue( // Call SortedListClass< T >::getNumElems()
        );

    void enqueue( // Calls SortedListClass< T >::insertValue()
        const T &enqueueVal
        );
    
    void dequeue( // Calls SortedListClass< T >::removeFront()
        );

    void printQueue(
        );
};
#include "QueueClass.inl"
#endif 

