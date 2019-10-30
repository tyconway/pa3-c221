#pragma once
// #ifndef SORTED_PRIORITY_QUEUE_H
// #define SORTED_PRIORITY_QUEUE_H 

#include <exception>
#include "PriorityQueue.h"
#include "Exception.h"

using namespace std;

template <class Type>
class SortedPQ : public PriorityQueue<Type> {
    list<Type> queue;
public:
    SortedPQ() {
    }

    ~SortedPQ() {
    }

    bool isEmpty() {
        return queue.empty();
    }

    int size() {
        return queue.size();
    }

    void insertItem ( Type data ) {
        if (queue.empty() || data > queue.back()) {
            queue.push_back(data);
            return;
        }
        for (auto it = queue.begin(); it != queue.end(); it++) {
            if (data < *it) {
                queue.insert(it, data);
                return;
            }
        }
        queue.push_back(data);
        return;
    }

    Type removeMin ( void ) {
        if (queue.empty()) throw EmptyPQ();
        Type remove = queue.front();
        queue.erase(queue.begin());
        return remove;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue () {
        if (queue.empty()) throw EmptyPQ();
        return queue.front();
   }
};

// #endif