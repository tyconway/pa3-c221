#pragma once
// #ifndef SORTED_PRIORITY_QUEUE_H
// #define SORTED_PRIORITY_QUEUE_H 

#include <exception>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

template <class Type>
class HeapPQ : public PriorityQueue<Type> {
    vector<Type> vec;
public:
    HeapPQ() {
    }

    ~HeapPQ() {
    }

    void insertItem ( Type data ) {
        printf("Inserted(%i)\n", data);
        vec.push_back(data);

        fixHeap();
        return;
    }

    Type removeMin () {
        if (vec.empty()) throw EmptyPQ();

        swap(0, vec.size() - 1);
        Type remove = vec.back();
        vec.pop_back();

        fixHeap();
        fixHeap();

        printf("Remove(%i)\n", remove);
        return remove;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue ( void ) {
        if (vec.empty()) throw EmptyPQ();
        printf("Min(%i)\n", vec[0]);
        return vec[0];
    }

    void fixHeap() {
        printf("Fixing heap:\n");
        int currentIndex = vec.size() - 1;
        while (currentIndex != -1) {
            print();
            Type current = vec[currentIndex];
            if (current < vec[parentIndex(currentIndex)]) {
                swap(currentIndex, parentIndex(currentIndex));
                currentIndex -= 1;
                continue;
            }
            currentIndex -= 1;
        }
    }

    int parentIndex(int childIndex) {
        return childIndex / 2;
    }

    void swap(int leftIndex, int rightIndex) {
        Type temp = vec[leftIndex];
        vec[leftIndex] = vec[rightIndex];
        vec[rightIndex] = temp;
    }

    void print() {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
};

// #endif