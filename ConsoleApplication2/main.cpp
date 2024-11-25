#include <iostream>
#include <string>
#include "Array.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "HashTable.h"
#include "BinaryTree.h"

void ArrayCommands(Array& arr) {
    std::string command;
    while (true) {
        std::cout << "Array >> ";
        std::cin >> command;

        if (command == "ADD") {
            std::string value;
            std::cin.ignore();
            std::getline(std::cin, value);
            Add(arr, value);
        }
        else if (command == "PRINT") {
            Print(arr);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void LinkedListCommands(NodeL*& list) {
    std::string command;
    while (true) {
        std::cout << "LinkedList >> ";
        std::cin >> command;

        if (command == "ADDHEAD") {
            int value;
            std::cin >> value;
            addHeadL(list, value);
        }
        else if (command == "PRINT") {
            printListL(list);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void DoubleLinkedListCommands(NodeLS*& head, NodeLS*& tail) {
    std::string command;
    while (true) {
        std::cout << "DoubleLinkedList >> ";
        std::cin >> command;

        if (command == "ADDHEAD") {
            int value;
            std::cin >> value;
            addHeadLS(head, tail, value);
        }
        else if (command == "PRINT") {
            printListLS(head);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void QueueCommands(Q& queue) {
    std::string command;
    while (true) {
        std::cout << "Queue >> ";
        std::cin >> command;

        if (command == "PUSH") {
            int value;
            std::cin >> value;
            AddQ(queue, value);
        }
        else if (command == "PRINT") {
            ShowQ(queue);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void StackCommands(S* stack) {
    std::string command;
    while (true) {
        std::cout << "Stack >> ";
        std::cin >> command;

        if (command == "PUSH") {
            int value;
            std::cin >> value;
            AddS(stack, value);
        }
        else if (command == "PRINT") {
            ShowS(stack);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void HashTableCommands(HashTable& hashTable) {
    std::string command;
    while (true) {
        std::cout << "HashTable >> ";
        std::cin >> command;

        if (command == "INSERT") {
            std::string key, value;
            std::cin >> key >> value;
            hashTable.insert(key, value);
        }
        else if (command == "PRINT") {
            hashTable.printTable();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

void BinaryTreeCommands(TNode*& root) {
    std::string command;
    while (true) {
        std::cout << "BinaryTree >> ";
        std::cin >> command;

        if (command == "INSERT") {
            int value;
            std::cin >> value;
            root = insert(root, value);
        }
        else if (command == "PRINT") {
            printBinaryTree(root);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

int main() {
    Array arr;
    CreateArray(arr, 10);
    NodeL* list = nullptr;
    NodeLS* dHead = nullptr;
    NodeLS* dTail = nullptr;
    Q queue;
    S stack;
    HashTable hashTable;
    TNode* root = nullptr;

    while (true) {
        std::string command;
        std::cout << ">> ";
        std::cin >> command;

        if (command == "ARRAY") {
            ArrayCommands(arr);
        }
        else if (command == "LINKEDLIST") {
            LinkedListCommands(list);
        }
        else if (command == "DOUBLELINKEDLIST") {
            DoubleLinkedListCommands(dHead, dTail);
        }
        else if (command == "QUEUE") {
            QueueCommands(queue);
        }
        else if (command == "STACK") {
            StackCommands(&stack);
        }
        else if (command == "HASHTABLE") {
            HashTableCommands(hashTable);
        }
        else if (command == "BINARYTREE") {
            BinaryTreeCommands(root);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    clearListL(list);
    clearListLS(dHead, dTail);
    ClearQueue(queue);
    ClearStack(&stack);
    hashTable.clear();
    clearTree(root);
    DeleteArray(arr);

    return 0;
}
