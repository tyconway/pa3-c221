#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

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
}