#ifndef LISTNODE_TEMPLATE_H_
#define LISTNODE_TEMPLATE_H_
template < class T >
class ListNodeClass
{
  private:
    ListNodeClass *prevNode; //Will point to the node that comes before
                             //this node in the data structure. Will be
                             //NULL if this is the first node.
    T nodeVal;      //The value contained within this node.
    ListNodeClass *nextNode; //Will point to the node that comes after
                             //this node in the data structure. Will be
                             //NULL if this is the last node.

  public:
    //The ONLY constructor for the list node class - it takes in the
    //newly created node's previous pointer, value, and next pointer,
    //and assigns them.
    ListNodeClass(
         ListNodeClass *inPrev,  //Address of node that comes before this one
         const T &inVal,//Value to be contained in this node
         ListNodeClass *inNext   //Address of node that comes after this one
         );

    //Sets the "next" pointer of a node. No return value.
    void setNextPointer(
         ListNodeClass *newNextPtr
         );

    //Returns the value stored within this node.
    T getValue(
         ) const;

    //Returns the address of the node that follows this node.
    ListNodeClass* getNext(
         ) const;

    //Returns the address of the node that comes before this node.
    ListNodeClass* getPrev(
         ) const;

    //Sets the object's previous node pointer to the value passed in.
    void setPreviousPointer(
         ListNodeClass *newPrevPtr
         );

    //This function DOES NOT modify "this" node. Instead, it uses
    //the pointers contained within this node to change the previous
    //and next nodes so that they point to this node appropriately.
    //In other words, if "this" node is set up suchthat its prevNode
    //pointer points to a node (call it "A"), and "this" node's
    //nextNode pointer points to a node (call it "B"), then calling
    //setBeforeAndAfterPointers results in the nodewe're calling
    //"A" to be updated so its "nextNode" points to"this" node, and
    //the node we're calling "B" is updates so its"prevNode" points
    //to "this" node, but "this" node itself remains unchanged.
    void setBeforeAndAfterPointers(
         );
};
#include "ListNodeClass.inl"
#endif

