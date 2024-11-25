#include "Stack.h"
#include <iostream>

void AddS(S* stack, int data) {
    Node* newNode = new Node{ data, nullptr };
    newNode->next = stack->head;
    stack->head = newNode;
}

void DelS(S* stack) {
    if (!stack->head) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node* temp = stack->head;
    stack->head = stack->head->next;
    delete temp;
}

void ShowS(S* stack) {
    Node* current = stack->head;
    while (current) {
        std::cout << current->numbr << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void ClearStack(S* stack) {
    while (stack->head) {
        DelS(stack);
    }
}
