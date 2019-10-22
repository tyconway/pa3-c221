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
public:
    UnsortedPQ() {
    }

    ~UnsortedPQ() {
        delete queue;
    }

    bool isEmpty() {
        return (queue->empty());
    }

    int size() {
        return queue->size();
    }
    
    void insertItem ( Type data ) {
        printf("Inserted(%i)\n", data);
        queue->push_back(data);
    }

    Type removeMin ( void ) {
        if (isEmpty()) { throw EmptyPQ(); }
        Type min = queue->front();
        auto index = queue->begin();
        for (auto it = queue->begin(); it != queue->end(); it++) {
            if (*it < min) {
                min = *it; 
                index = it;
            }
        }
        queue->erase(index);
        printf("Erased(%i)\n", min);
        return min;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue () {
        if (isEmpty()) { throw EmptyPQ(); }
        Type min = queue->front();
        for (auto it = queue->begin(); it != queue->end(); it++) {
            if (*it < min) min = *it; 
        }
        printf("Min(%i)\n", min);
        return min;
    }
};

// #endif