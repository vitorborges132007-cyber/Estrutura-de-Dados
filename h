#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include <string>
using namespace std;

struct Node {
    string value;
    Node* next;
};

class ArraySequence{
private:
    Node* head;
    int quantity;

public:

    ArraySequence();
    ~ArraySequence();
    int size();
    bool isEmpty();
    bool contains(string s);
    bool add(string s, int position);
    string get(int position);
    bool remove(int position);
    void print();
};

#endif