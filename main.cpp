#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

int main() {
    cout << endl; 

    string file = "numbers.txt";
    vector<int> data = parseFile(file);
    // pick which implementation:
    int type = data[0];
    // PriorityQueue<int>* queue;
    // if (type == 0) {
    //     delete queue;
    //     UnsortedPQ<int>* queue = new UnsortedPQ<int>();
    //     printf("UnsortedPQ created\n");
    // }
    // else if (type == 1) {
    //     delete queue;
    //     SortedPQ<int>* queue = new SortedPQ<int>();
    //     printf("SortedPQ created\n");
    // }
    // else if (type == 2) {
    //     delete queue;
    //     HeapPQ<int>* queue = new HeapPQ<int>();
    //     printf("HeapPQ created\n");
    // }
    // else {
    //     return 0;
    // }
    HeapPQ<int>* queue = new HeapPQ<int>();

    queue->insertItem(70);
    queue->insertItem(16);
    queue->insertItem(42);
    queue->insertItem(51);
    // queue->insertItem(42);
    queue->insertItem(42);
    queue->insertItem(2);
    queue->insertItem(3);
    queue->print();
    queue->removeMin();
    queue->print();
    queue->removeMin();
    queue->print();
    queue->removeMin();
    queue->print();
    queue->removeMin();
    queue->print();
    queue->removeMin();
    queue->print();
    queue->removeMin();
    queue->print();
    queue->removeMin();
    queue->print();
    // queue->removeMin();
    // queue->removeMin();
    
}