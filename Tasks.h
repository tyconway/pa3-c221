#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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



#endif