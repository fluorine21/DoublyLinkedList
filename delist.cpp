#include "delist.h"

DEList::DEList(){
   head = new DEItem();
   tail = new DEItem();
   head->val = 0;
   head->prev = NULL;
   head->next = tail;
   tail->val = 0;
   tail->prev = head;
   tail->next = NULL;
   length = 0;

}
  // Destructor to clean-up memory of current list
DEList::~DEList(){
    DEItem* point = head;

    while (point)
    {
        DEItem* next = point->next;
        delete point;
        point = next;
    }

}
// returns a Boolean 'true' if the list is empty
bool DEList::empty(){
 if(length == 0)
    return true;
 return false;
  
}
  // returns number of items in the list
int DEList::size(){
 return length;
}
  // returns front item or -1 if empty list
int DEList::front(){
   if(length == 0)
      return -1;
   DEItem* lastItem = tail->prev;
   return lastItem->val;   
}
  // returns back item or -1 if empty list
int DEList::back(){
   if(length == 0)
      return -1;
   DEItem* firstItem = head->next;
   return firstItem->val;   
}
  // Adds a new integer to the front of the list
void DEList::push_front(int new_val){
   DEItem* newItem = new DEItem();//Creates a new item ready to be added to the list
   newItem->val = new_val;
   newItem->next = tail;//Fixes pointers
   newItem->prev = tail->prev;
   (tail->prev)->next = newItem;
   tail->prev = newItem;
   length++;
}
  // Adds a new integer to the back of the list
void DEList::push_back(int new_val){
   DEItem* newItem = new DEItem();//Creates a new item ready to be added to the list
   newItem->val = new_val;//Fixes pointers to point to correct location
   newItem->next = head->next;
   newItem->prev = head;
   head->next = newItem;
   (newItem->next)->prev = newItem;
   length++;
}
  // Removes the front item of the list (if it exists)
void DEList::pop_front(){
   if(length == 0)
      return;
   DEItem* lastItem = tail->prev;
   tail->prev = lastItem->prev;
   delete lastItem;
   (tail->prev)->next = tail;
   length--;
   
}
  // Removes the back item of the list (if it exists)
void DEList::pop_back(){
   if(length == 0)
      return;
   DEItem* firstItem = head->next;
   head->next = firstItem->next;//Advances head next ponter past item to be deleted
   delete firstItem;
   (head->next)->prev = head;
   length--;
}
