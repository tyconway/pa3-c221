#pragma once
// #ifndef SORTED_PRIORITY_QUEUE_H
// #define SORTED_PRIORITY_QUEUE_H 

#include <exception>
#include <list>
#include "PriorityQueue.h"
#include "Node.h"
#include "Exception.h"

using namespace std;

template <class Type>
class UnsortedPQ : public PriorityQueue<Type> {
    list<Type> *queue = new list<Type>();
    int s;
public:
    UnsortedPQ() {
        s = 0;
    }

    ~UnsortedPQ() {
    }

    bool isEmpty() {
        return (queue->empty());
    }
    
    void insertItem ( Type data ) {
        queue->push_back(data);
    }

    Type removeMin ( void ) {
        return;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue () {
        if (isEmpty()) { throw EmptyPQ(); }
        return 1;
    }
};

// #endif