#include "HashTable.h"
#include <iostream>
#include <fstream>

HashTable::HashTable() {
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    clear();
}

int HashTable::hashFunction(const std::string& key) const {
    int hash = 0;
    for (char ch : key) {
        hash += ch;
    }
    return hash % tableSize;
}

void HashTable::insert(const std::string& key, const std::string& value) {
    int index = hashFunction(key);
    NodeH* newNode = new NodeH{ key, value, nullptr };

    if (!table[index]) {
        table[index] = newNode;
    }
    else {
        NodeH* current = table[index];
        while (current) {
            if (current->key == key) {
                current->value = value;
                delete newNode;
                return;
            }
            if (!current->next) {
                current->next = newNode;
                return;
            }
            current = current->next;
        }
    }
}

std::string HashTable::get(const std::string& key) const {
    int index = hashFunction(key);
    NodeH* current = table[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return "Key not found";
}

void HashTable::remove(const std::string& key) {
    int index = hashFunction(key);
    NodeH* current = table[index];
    NodeH* previous = nullptr;

    while (current) {
        if (current->key == key) {
            if (previous) {
                previous->next = current->next;
            }
            else {
                table[index] = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
    std::cout << "Key not found for removal" << std::endl;
}

void HashTable::printTable() const {
    for (int i = 0; i < tableSize; i++) {
        NodeH* current = table[i];
        if (current) {
            std::cout << "[" << i << "]: ";
            while (current) {
                std::cout << "{" << current->key << ": " << current->value << "} ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
}

void HashTable::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }

    for (int i = 0; i < tableSize; i++) {
        NodeH* current = table[i];
        while (current) {
            file << current->key << " " << current->value << std::endl;
            current = current->next;
        }
    }
    file.close();
}

void HashTable::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    clear();
    std::string key, value;
    while (file >> key >> value) {
        insert(key, value);
    }
    file.close();
}

void HashTable::clear() {
    for (int i = 0; i < tableSize; i++) {
        NodeH* current = table[i];
        while (current) {
            NodeH* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}
