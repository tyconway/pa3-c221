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
        s = 0;
    }

    ~UnsortedPQ() {
    }

    bool isEmpty() {
        return (s == 0);
    }
    
    void insertItem ( Type data ) {
        Node<Type>* inserted = new Node<Type>(data);
        if (isEmpty()) {
            head = inserted;
            tail = inserted;
            s++;
            printf("Inserted(%i)\n", inserted->getData());
            return;
        }
        tail->setNext(inserted);
        inserted->setPrev(tail);
        tail = inserted;
        s++;
        printf("Inserted(%i)\n", inserted->getData());
        return;
    }

    Type removeMin ( void ) {
        return;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue () {
        // if (isEmpty()) ...
        printf("here\n");
        Type min = head->getData();
        Node<Type>* curr = head;
        while (curr) {
            if (curr->getData() < min) {
                min = curr->getData();
            }
            curr = curr->getNext();
        }
        return min;
    }
};

// #endif