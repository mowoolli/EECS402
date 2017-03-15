#include <iostream>
#include "ListNodeClass.h"
#include "SortedListClass.h"
#include "QueueClass.h"

using namespace std;
int main()
{ 
  cout << endl;
/*
  int A = 2;
  int B = 1;
  int C = 5;
  int D = 12;
  int E = -2;
  int F = 0;
  int G = 3;
*/
  QueueClass< int > *myQueue;
  myQueue = new QueueClass< int >;
  
  myQueue->QueueClass< int >::enqueue(2);
  myQueue->QueueClass< int >::enqueue(1);
  myQueue->QueueClass< int >::enqueue(3);
  myQueue->QueueClass< int >::enqueue(4);
  myQueue->QueueClass< int >::enqueue(8);
  myQueue->QueueClass< int >::enqueue(6);
  myQueue->QueueClass< int >::printQueue();
  myQueue->QueueClass< int >::dequeue();
  myQueue->QueueClass< int >::dequeue();
  myQueue->QueueClass< int >::printQueue();

  char A = 'a';
  char B = 'r';
  char C = 'F';
  char D = 'e';
  char E = 'n';
  char F = 'y';
  char G = 'r';
  char H = 'e';
  char I = 'K';

  SortedListClass< char > *myList;
  myList = new SortedListClass< char >;

//  myList->SortedListClass< char >::printForward();
//  myList->SortedListClass< char >::printBackward();
  myList->SortedListClass< char >::insertValue(A);
  myList->SortedListClass< char >::insertValue(B);
  myList->SortedListClass< char >::insertValue(C);
  myList->SortedListClass< char >::insertValue(D);
  myList->SortedListClass< char >::insertValue(E);
  myList->SortedListClass< char >::insertValue(F);
  myList->SortedListClass< char >::insertValue(G);
  myList->SortedListClass< char >::insertValue(H);
  myList->SortedListClass< char >::insertValue(I);
  myList->SortedListClass< char >::printForward();
  myList->SortedListClass< char >::printBackward();

  myList->SortedListClass< char >::getElemAtIndex(2,F);
  char stuff = myList->SortedListClass< char >::getElemAtIndex(2,F);
  cout << "stuff = " << stuff << endl;

//  myList->SortedListClass< char >::clear();
  myList->SortedListClass< char >::printForward();
  myList->SortedListClass< char >::printBackward();
  myList->SortedListClass< char >::removeFront(A);
  myList->SortedListClass< char >::printForward();
  myList->SortedListClass< char >::removeFront(A);
  myList->SortedListClass< char >::printForward();
  myList->SortedListClass< char >::removeFront(A);
  myList->SortedListClass< char >::printForward();
  
//  char ret = myList->SortedListClass< char >::removeFront(A);
//  cout << ret << endl;

  int num = myList->SortedListClass< char >::getNumElems();
  cout << num << endl;
  cout << num << endl;

  myList->SortedListClass< char >::clear();
  char ret = myList->SortedListClass< char >::removeFront(I);
  cout << ret << endl;

  myList->SortedListClass< char >::insertValue(A);
  myList->SortedListClass< char >::insertValue(B);
  myList->SortedListClass< char >::insertValue(C);
  myList->SortedListClass< char >::insertValue(D);
  myList->SortedListClass< char >::insertValue(E);
  myList->SortedListClass< char >::insertValue(F);
  myList->SortedListClass< char >::insertValue(G);
  myList->SortedListClass< char >::insertValue(H);
  myList->SortedListClass< char >::insertValue(I);
  myList->SortedListClass< char >::printForward();
  myList->SortedListClass< char >::printBackward();
  myList->SortedListClass< char >::clear();
  myList->SortedListClass< char >::printForward();
  myList->SortedListClass< char >::printBackward();


  return (0);
}
