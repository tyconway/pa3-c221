#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
// #include "PriorityQueue.h"
#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"

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
void testSuite(PriorityQueue<Type>& queue) {
    cout << queue.isEmpty() << endl;
}

int main() {
    string hey = "Hey\n";
    string green = "\033[32m";
    string normal = "\033[0m";

    cout << endl; 

    string file = "numbers.txt";
    // Converts numbers.txt to vector
    vector<int> data = parseFile(file);
    int type = data[0];
    if (type == 0) {
        UnsortedPQ<int>* queue = new UnsortedPQ<int>();
        testSuite(*queue);
    }
    else if (type == 1) {
        SortedPQ<int>* queue = new SortedPQ<int>();
        testSuite(*queue);
    }
    else if (type == 2) {
        HeapPQ<int>* queue = new HeapPQ<int>();
        testSuite(*queue);
    }
    else {
        return 0;
    }

}