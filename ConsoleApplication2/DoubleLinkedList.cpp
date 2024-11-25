#include "DoubleLinkedList.h"
#include <iostream>

void addHeadLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* newNode = new NodeLS;
    newNode->data = value;
    newNode->next = head;
    newNode->previous = nullptr;
    if (head) {
        head->previous = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
}

void addTailLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* newNode = new NodeLS;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = tail;
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

void deleteHeadLS(NodeLS*& head, NodeLS*& tail) {
    if (!head) return;
    NodeLS* temp = head;
    head = head->next;
    if (head) {
        head->previous = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
}

void deleteTailLS(NodeLS*& head, NodeLS*& tail) {
    if (!tail) return;
    NodeLS* temp = tail;
    tail = tail->previous;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
}

bool deleteByValueLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (!current) return false;
    if (current->previous) {
        current->previous->next = current->next;
    }
    else {
        head = current->next;
    }
    if (current->next) {
        current->next->previous = current->previous;
    }
    else {
        tail = current->previous;
    }
    delete current;
    return true;
}

NodeLS* searchLS(NodeLS* head, int value) {
    while (head) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

void printListLS(NodeLS* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void clearListLS(NodeLS*& head, NodeLS*& tail) {
    while (head) {
        deleteHeadLS(head, tail);
    }
}
