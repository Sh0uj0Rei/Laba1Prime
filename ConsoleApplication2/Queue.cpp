#include "Queue.h"
#include <iostream>

void AddQ(Q& queue, int number) {
    Node* newnode = new Node;
    newnode->numbr = number;
    newnode->next = nullptr;

    if (!queue.first) {
        queue.first = newnode;
        queue.last = newnode;
    }
    else {
        queue.last->next = newnode;
        queue.last = newnode;
    }
}

void DelQ(Q& queue) {
    if (!queue.first) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node* temp = queue.first;
    queue.first = queue.first->next;
    if (!queue.first) {
        queue.last = nullptr;
    }
    delete temp;
}

void ShowQ(const Q& queue) {
    Node* current = queue.first;
    while (current) {
        std::cout << current->numbr << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void ClearQueue(Q& queue) {
    while (queue.first) {
        DelQ(queue);
    }
}
