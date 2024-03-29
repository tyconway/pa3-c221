#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdlib>
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
        cout << queue.removeMin() << " ";
    }
    cout << normal << endl;
}

void log_csv(string filename, chrono::duration<double, nano> elapsed, int currPushCount)
{
    double millisecondsDenominator = 1000000; 
    double elapsed_seconds = elapsed.count()/millisecondsDenominator;
    ofstream ofs;
    string csv_filename = filename + ".csv";
    ofs.open(csv_filename, ios::app);
    ofs << currPushCount << "," << elapsed_seconds << "\n";
    ofs.close();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TASKS
void taskNumbers() {
    
    // Converts numbers.txt to vector
    string file = "numbers.txt";
    vector<int> data = parseFile(file);
    int type = data[0];
    vector<int> numbers(data.begin() + 2, data.end());

    cout << "\nSorting " << data[1] << " numbers from numbers.txt:\n";
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
    cout << endl;
}

void taskInsert(int n, int logInterval) {
    string green = "\033[32m";
    string normal = "\033[0m";
    string blue = "\033[36m";
    // time insert to each implementation
    cout << "Insert and log " << n << " numbers:\n";
    cout << "Unsorted: ";
    srand(time(0));
    UnsortedPQ<int> *unsorted = new UnsortedPQ<int>();
    auto start = chrono::high_resolution_clock::now();
    for (int insert = 0; insert <= n; insert++) {
        int r = (rand() % 1000) + 1;
        unsorted->insertItem(r);
        if (insert % logInterval == 0) {
            auto curr = chrono::high_resolution_clock::now();
            auto elapsed = curr - start;
            log_csv("./logs/unsorted_insert", elapsed, insert);
        }
    }
    cout << "\rUnsorted: " << green << "Done";
    cout << normal << endl;
    delete unsorted;

    cout << "Sorted: ";
    SortedPQ<int> *sorted = new SortedPQ<int>();
    start = chrono::high_resolution_clock::now();
    for (int insert = 0; insert <= n; insert++) {
        int r = (rand() % 1000) + 1;
        sorted->insertItem(r);
        if (insert % logInterval == 0) {
            auto curr = chrono::high_resolution_clock::now();
            auto elapsed = curr - start;
            log_csv("./logs/sorted_insert", elapsed, insert);
        }
    }
    delete sorted;
    cout << "\rSorted: " << green << "Done";
    cout << normal << endl;

    cout << "Heap: ";
    HeapPQ<int> *heap = new HeapPQ<int>();
    start = chrono::high_resolution_clock::now();
    for (int insert = 0; insert <= n; insert++) {
        int r = (rand() % 1000) + 1;
        heap->insertItem(r);
        if (insert % logInterval == 0) {
            auto curr = chrono::high_resolution_clock::now();
            auto elapsed = curr - start;
            log_csv("./logs/heap_insert", elapsed, insert);
        }
    }
    delete heap;
    cout << "\rHeap: " << green << "Done";
    cout << normal << endl;
}

template <class Type>
void testInsertRemove(PriorityQueue<Type>& queue, int n) {
    for (int insert = 0; insert < n; insert++) {
        // Random:
        int r = (rand() % 1000) + 1;
        queue.insertItem(r);

        // Decreasing:
        // int num = (insert - n) * (-1);
        // queue.insertItem(num);

        // Increasing:
        // queue.insertItem(insert);
    }
    for (int insert = n; insert != 0; insert--) {
        queue.removeMin();
    }
    return;
}

void taskInsertRemove(int n, int logInterval) {
    cout << endl << "Insert, remove and log " << n << " numbers: ";

    for (int i = 0; i < n; i += logInterval) {
	cout << "\nBegin";
        UnsortedPQ<int> *unsorted = new UnsortedPQ<int>();
        auto start = chrono::high_resolution_clock::now();
        testInsertRemove(*unsorted, i);
        auto curr = chrono::high_resolution_clock::now();
        auto elapsed = curr - start;
        log_csv("./logs/unsorted_insert_remove", elapsed, i);
        delete unsorted;

        SortedPQ<int> *sorted = new SortedPQ<int>();
        start = chrono::high_resolution_clock::now();
        testInsertRemove(*sorted, i);
        curr = chrono::high_resolution_clock::now();
        elapsed = curr - start;
        log_csv("./logs/sorted_insert_remove", elapsed, i);
        delete sorted;

        HeapPQ<int> *heap = new HeapPQ<int>();
        start = chrono::high_resolution_clock::now();
        testInsertRemove(*heap, i);
        curr = chrono::high_resolution_clock::now();
        elapsed = curr - start;
        log_csv("./logs/heap_insert_remove", elapsed, i);
        delete heap;

        cout << "\r" << i << "/" << n;
    }
    string green = "\033[32m";
    cout << green << "\nDone\n\033[0m";
}

#endif
