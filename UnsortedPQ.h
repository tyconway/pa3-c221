#pragma once
// #ifndef SORTED_PRIORITY_QUEUE_H
// #define SORTED_PRIORITY_QUEUE_H 

#include <exception>
#include "PriorityQueue.h"

using namespace std;

template <class Type>
class UnsortedPQ : public PriorityQueue<Type> {
public:
    UnsortedPQ() {
        cout << "Apposto.\n";
    }
    ~UnsortedPQ() {

    }
   void insertItem ( Type data ) {
       return;
   }
   Type removeMin ( void ) {
       return;
   }

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ) {
       return;
   }
};

// #endif