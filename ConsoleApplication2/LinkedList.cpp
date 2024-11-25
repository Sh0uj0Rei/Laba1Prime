#include "LinkedList.h"
#include <iostream>

void addHeadL(NodeL*& head, int value) {
    NodeL* newNode = new NodeL;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void addTailL(NodeL*& head, int value) {
    NodeL* newNode = new NodeL;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        NodeL* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteHeadL(NodeL*& head) {
    if (!head) return;
    NodeL* temp = head;
    head = head->next;
    delete temp;
}

void deleteTailL(NodeL*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    NodeL* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

bool deleteByValueL(NodeL*& head, int value) {
    if (!head) return false;
    if (head->data == value) {
        deleteHeadL(head);
        return true;
    }

    NodeL* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        NodeL* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }
    return false;
}

NodeL* searchL(NodeL* head, int value) {
    NodeL* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void printListL(NodeL* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void clearListL(NodeL*& head) {
    while (head) {
        deleteHeadL(head);
    }
}
