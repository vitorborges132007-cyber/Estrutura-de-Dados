#include <iostream>
#include "ArraySequence.h"

using namespace std;

ArraySequence::ArraySequence(){
    head = nullptr;
    quantity = 0;
}

ArraySequence::~ArraySequence() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int ArraySequence::size(){
    return quantity;
}

bool ArraySequence::isEmpty(){
    if (quantity == 0){
        return true;
    }
    
    return false;
}

bool ArraySequence::contains(string s){
    Node* current = head;
    while (current != nullptr) {
        if (current->value == s) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool ArraySequence::add(string s, int position){
    if (position < 1 || position > quantity + 1 || quantity >= 10) {
        return false;
    }
    
    Node* newNode = new Node();
    newNode->value = s;
    newNode->next = nullptr;

    
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } 
    
    else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    quantity++;
    return true;
}

string ArraySequence::get(int position){
    if (position < 1 || position > quantity) {
        return "";
    }
    
    Node* current = head;

    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    
    return current->value;
    
}

bool ArraySequence::remove(int position){
    if (position < 1 || position > quantity){
        return false;
    }
    
    Node* deletar = nullptr;
    if (position == 1) {
        deletar = head;
        head = head->next;
    } 
    else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        deletar = current->next;
        current->next = deletar->next;
    }

    delete deletar;
    quantity--;
    return true;
}

void ArraySequence::print(){
    cout << "[";
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "]" << endl;
}