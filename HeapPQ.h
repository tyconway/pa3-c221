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

    bool isEmpty() {
        return (vec.empty());
    }

    int size() {
        return vec.size();
    }

    void insertItem ( Type data ) {
        // printf("Inserted(%i)\n", data);
        vec.push_back(data);

        // fixHeap();
        upHeap(vec.size() - 1);
        return;
    }

    Type removeMin () {
        if (vec.empty()) throw EmptyPQ();

        swap(0, vec.size() - 1);
        Type remove = vec.back();
        vec.pop_back();
        // printf("\nRemoved(%i)\n", remove);

        // fixHeap();
        downHeap(0);

        return remove;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue ( void ) {
        if (vec.empty()) throw EmptyPQ();
        return vec[0];
    }

    void fixHeap() {
        int currentIndex = vec.size() - 1;
        while (currentIndex != -1) {
            Type current = vec[currentIndex];
            if (current < vec[parentIndex(currentIndex)]) {
                swap(currentIndex, parentIndex(currentIndex));
                currentIndex -= 1;
                continue;
            }
            currentIndex -= 1;
        }
    }

    void upHeap(int child) {
        // cout << "upHeap: ";
        // print();
        // cout << "\n";
        int parent = parentIndex(child);
        if (vec[child] >= vec[parent] || child == 0) {
            return;
        }
        else if (vec[child] < vec[parent]) {
            swap(child, parent);
            upHeap(parent);
        }
    }

    void downHeap(int parent) {
        // cout << "\n";
        // cout << "downHeap: ";
        // print();
        int left = leftChildIndex(parent);
        int right = rightChildIndex(parent);
        if (left == -1 || right == - 1) { return; }
        if (vec[left] >= vec[parent] && vec[right] >= vec[parent]) { return; }

        // If we've reached here, then vec[parent] > one of the children
        if (vec[left] < vec[right]) {
            swap(left, parent);
            downHeap(left);
        }
        else if (vec[left] >= vec[right]) {
            swap(right, parent);
            downHeap(right);
        }
    }

    int parentIndex(int childIndex) {
        int parent = (childIndex - 1) / 2;
        if (parent < 0) { return 0; }
        return parent;
    }

    int leftChildIndex(int parentIndex) {
        int left = 2 * parentIndex + 1;
        if (left > vec.size() - 1) { return -1; }
        return left;
    }

    int rightChildIndex(int parentIndex) {
        int right = 2 * parentIndex + 2;
        int last = vec.size() - 1;
        if (right > last) { return -1; }
        return right;
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
    }
};

// #endif