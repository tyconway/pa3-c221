#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"

// UTILITIES
vector<int> parseFile(string filename) {
    ifstream fin;
    fin.open(filename);
    int number;
    vector<int> vector;
    while (fin >> number) {
        vector.push_back(number);
    }
    return vector;
}

template <class Type>
void insertNumbersPrint(PriorityQueue<Type>& queue, vector<int>& numbers) {
    string green = "\033[32m";
    string normal = "\033[0m";

    for (auto num : numbers) {
        queue.insertItem(num);
    }

    for (auto num : numbers) {
        cout << green << queue.removeMin() << " ";
    }
    cout << normal << endl;
}

void log_csv(string filename, chrono::duration<double, nano> elapsed, int currPushCount)
{
    double millisecondsDenominator = 1000000; 
    auto elapsed_seconds = elapsed/millisecondsDenominator;
    ofstream ofs;
    ofs.open(filename, ios::app);
    ofs << currPushCount << "," << elapsed_seconds.count() << "\n";
    ofs.close();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TASKS
void taskNumbers() {
    cout << endl; 

    // Converts numbers.txt to vector
    string file = "numbers.txt";
    vector<int> data = parseFile(file);
    int type = data[0];
    vector<int> numbers(data.begin() + 2, data.end());

    if (type == 0) {
        UnsortedPQ<int>* queue = new UnsortedPQ<int>();
        insertNumbersPrint(*queue, numbers);
    }
    else if (type == 1) {
        SortedPQ<int>* queue = new SortedPQ<int>();
        insertNumbersPrint(*queue, numbers);
    }
    else if (type == 2) {
        HeapPQ<int>* queue = new HeapPQ<int>();
        insertNumbersPrint(*queue, numbers);
    }
    else {
        printf("Invalid type requested.");
        return;
    }
}

void taskInsert(int n, int logInterval) {
    // time insert to each implementation
    UnsortedPQ<int> *unsorted = new UnsortedPQ<int>();
    auto start = chrono::high_resolution_clock::now();
    for (int insert = 0; insert <= n; insert++) {
        unsorted->insertItem(insert);
        if (insert % logInterval == 0) {
            auto curr = chrono::high_resolution_clock::now();
            auto elapsed = curr - start;
            log_csv("./logs/unsorted_insert", elapsed, insert);
            cout << "\rUnsorted: " << insert;
        }
    }
    delete unsorted;
    cout << endl;

    SortedPQ<int> *sorted = new SortedPQ<int>();
    start = chrono::high_resolution_clock::now();
    for (int insert = 0; insert <= n; insert++) {
        sorted->insertItem(insert);
        if (insert % logInterval == 0) {
            auto curr = chrono::high_resolution_clock::now();
            auto elapsed = curr - start;
            log_csv("./logs/sorted_insert", elapsed, insert);
            cout << "\rSorted: " << insert;
        }
    }
    delete sorted;
    cout << endl;

    HeapPQ<int> *heap = new HeapPQ<int>();
    start = chrono::high_resolution_clock::now();
    for (int insert = 0; insert <= n; insert++) {
        heap->insertItem(insert);
        if (insert % logInterval == 0) {
            auto curr = chrono::high_resolution_clock::now();
            auto elapsed = curr - start;
            log_csv("./logs/heap_insert", elapsed, insert);
            cout << "\rHeap: " << insert;
        }
    }
    delete heap;
    cout << endl;
}

#endif