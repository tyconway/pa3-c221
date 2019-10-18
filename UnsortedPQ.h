#pragma once
// #ifndef SORTED_PRIORITY_QUEUE_H
// #define SORTED_PRIORITY_QUEUE_H 

#include <exception>
#include "PriorityQueue.h"
#include "Node.h"

using namespace std;

template <class Type>
class UnsortedPQ : public PriorityQueue<Type> {
    Node<Type>* head;
    Node<Type>* tail;
    int s;
public:
    UnsortedPQ() {
        head = nullptr;
        tail = nullptr;
        s = 0;
    }
    ~UnsortedPQ() {
    }
    void insertItem ( Type data ) {
        Node<Type> inserted = new Node<Type>(data);
        if (this->size() == 0) {
            head->setNext(inserted);
            tail->setPrev(inserted);
            s++;
            return;
        }
        tail->setNext(inserted);
        inserted->setPrev(tail->getPrev);
        tail = inserted;
        s++;
        return;
    }
    Type removeMin ( void ) {
        return;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue () {
        // if (isEmpty()) ...
        Type max = head->getData();
        Node<Type>* curr = head;
        while (curr) {
            if (curr->getData() > max) {
                max = curr->getData();
            }
        }
        return max;
    }
};

// #endif