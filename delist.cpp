#include "delist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

DEList::DEList() { // constructor
    head = NULL;
    tail = NULL;
    num_nodes = 0;
}


DEList::~DEList() { //destructor to clean up memory
    
    while (head != NULL) {
        DEItem* temp;
        temp = head;
        head = head->next;
        delete temp;

    }
}


  // returns a Boolean 'true' if the list is empty
bool DEList::empty() {
    if (head == NULL && tail == NULL) {
        return true;
    } else {
        return false;
    }
}

        
  // returns number of items in the list
int DEList::size() {
    return num_nodes;
}
        
        
  // returns front item or -1 if empty list
int DEList::front() {
    if (size() == 0) {
        return -1;
    } else {
        return head->val;
    }
}
   
        
  // returns back item or -1 if empty list
int DEList::back() {
    if (size() == 0) {
        return -1;
    } else {
        return tail->val;
    }
}
        
  // Adds a new integer to the front of the list
void DEList::push_front(int new_val) {
    
    DEItem* temp = new DEItem;
    temp->val = new_val;
    
    if (head == NULL) { // allocate new item and make it the only item in list
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
        num_nodes++;
    } else { // add new item to front, which will be the new head
        head->prev = temp;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        num_nodes++;
    }
}
        
        
  // Adds a new integer to the back of the list
void DEList::push_back(int new_val) {
    
    DEItem* temp = new DEItem;
    temp->val = new_val;
    
    if (tail == NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        tail = temp;
        head = temp;
        num_nodes++;
    } else {
        tail->next = temp;
        temp->next = NULL;
        temp->prev = tail;
        tail = temp;   
        num_nodes++;
    }
}
        
        
  // Removes the front item of the list (if it exists)
void DEList::pop_front() {
    if (size() == 0) {
        return;
    }
    DEItem*temp = head;
    head = temp->next;
    if(head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    num_nodes--;
    delete temp;
}
        
        
  // Removes the back item of the list (if it exists)
void DEList::pop_back() {
    if (size() == 0) {
        return;
    }
    DEItem*temp = tail;
    tail = tail->prev;
    if(tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    num_nodes--;
    delete temp;
}
