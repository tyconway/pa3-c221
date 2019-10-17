#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// #include "PriorityQueue.h"
#include "SortedPQ.h"

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

int main() {
    string file = "numbers.txt";
    vector<int> data = parseFile(file);
    // pick which implementation:
    int type = data[0];
    PriorityQueue<int>* queue;
    if (type == 0) {
        // queue = new UnsortedPQ<int>();
    }
    else if (type == 1) {
        queue = new SortedPQ<int>();
    }
    else if (type == 2) {
        // queue = new HeapPQ<int>();
    }
    else {
        return 0;
    }
    cout << "here";
}