#include "Array.h"
#include <fstream>
#include <iostream>

void CreateArray(Array& arr, int capac) {
    arr.data = new std::string[capac];
    arr.size = 0;
    arr.capacity = capac;
}

void Add(Array& arr, const std::string& value) {
    if (arr.size == arr.capacity) {
        std::string* newdata = new std::string[arr.capacity * 2];
        for (int i = 0; i < arr.size; i++) {
            newdata[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newdata;
        arr.capacity *= 2;
    }
    arr.data[arr.size] = value;
    arr.size++;
}

void AddIndex(Array& arr, int index, const std::string& value) {
    if (index < 0 || index > arr.size) {
        std::cerr << "index out of array bounds" << std::endl;
        return;
    }
    if (arr.size >= arr.capacity) {
        std::string* newdata = new std::string[arr.capacity * 2];
        for (int i = 0; i < arr.size; i++) {
            newdata[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newdata;
        arr.capacity *= 2;
    }
    for (int i = arr.size; i > index; i--) {
        arr.data[i] = arr.data[i - 1];
    }
    arr.data[index] = value;
    arr.size++;
}

std::string Getin(const Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        std::cerr << "index out of array bounds" << std::endl;
        return "";
    }
    return arr.data[index];
}

void Delin(Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        std::cerr << "index out of array bounds" << std::endl;
        return;
    }
    for (int i = index; i < arr.size - 1; i++) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
}

void Setin(Array& arr, int index, const std::string& value) {
    if (index < 0 || index >= arr.size) {
        std::cerr << "index out of array bounds" << std::endl;
        return;
    }
    arr.data[index] = value;
}

void DeleteArray(Array& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

void Print(const Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

int Length(const Array& arr) {
    return arr.size;
}

void WriteArrayToFile(const Array& arr, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return;
    }
    for (int i = 0; i < arr.size; i++) {
        outFile << arr.data[i] << std::endl;
    }
    outFile.close();
    std::cout << "File was written: " << filename << std::endl;
}

void ReadArrayFromFile(Array& arr, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return;
    }

    DeleteArray(arr);
    CreateArray(arr, 10);

    std::string value;
    while (std::getline(inFile, value)) {
        Add(arr, value);
    }
    inFile.close();
}