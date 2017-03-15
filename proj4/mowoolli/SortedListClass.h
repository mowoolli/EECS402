#ifndef SORTEDLIST_TEMPLATE_H_
#define SORTEDLIST_TEMPLATE_H_
template < class T >
class SortedListClass
{
  private:
    ListNodeClass< T > *head;  //Points to the first node in a list, or NULL
                          //if list is empty.
    ListNodeClass< T > *tail;  //points to the last node in a list, or NULL
                          //if list is empty.

  public:
    //Default Constructor. Will properly intitialize a list to
    //be an empty list, to which values can be added.
    SortedListClass(
         );

    //Clears the list to an emoty state without resulting in any
    //memory leaks.
    void clear(
         );

    //Allows the user to insert a value into the list. Since this
    //is a sorted list, there is no need to specify where in the list 
    //to insert the element. It will insert it in the appropriate 
    //location based on the value being inserted. If the node value
    //being inserted is found to be "equal to" one or more node values
    //already in the list, the newly inserted node will be placed AFTER
    //the previuously inserted nodes.
    void insertValue(
         const T &valToInsert //The value to insert into the list
         );

    //Prints the contents of the list from head to tail to the screen.
    //Begins with a line reading "Forward List Contents Follow:", then
    //prints one list element per line, indented two spaces, then prints 
    //the line "End Of List Contents" to indicate the end of the list.
    void printForward(
         ) const;

    //Prints the contents of the list from tail to head to the screen.
    //Begins with a line reading "Backward List Contents Follow:", then 
    //prints one list element per line, indented two spaces, then prints
    //the line "End Of List Contents" to indecate the end of the list.
    void printBackward(
         ) const;

    //Removes the front item from the list and returns the value that
    //was contained in it via the reference parameter. If the list
    //was empty, the function returns false to indicate failure, and 
    //the contents of the reference parameter upon return is undefined.
    //If the list was not empty and the first item was successfully
    //removed, true is returned, and the reference parameter will 
    //be set to the item that was removed.
    bool removeFront(
         T &theVal
         );

    //Returns the number of nodes contained in the list.
    int getNumElems(
         ) const;

    //Provides the value stored in the node at index provided in the 
    //"index" parameter. If the index is out of range, then outVal
    //remains unchanged and false is returned. Otherwise, the function
    //returns true, and the reference parameter outVal will contain
    //a copy of the value at that location.
    bool getElemAtIndex(
         const int index,
         T &outVal
          );
};
#include "SortedListClass.inl"
#endif
