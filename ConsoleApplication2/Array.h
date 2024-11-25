#include <string>
#include <iostream>

struct Array {
    std::string* data; // указатель на массив строк
    int size;
    int capacity;
};

void CreateArray(Array& arr, int capac);
void Add(Array& arr, const std::string& value);
void AddIndex(Array& arr, int index, const std::string& value);
std::string Getin(const Array& arr, int index);
void Delin(Array& arr, int index);
void Setin(Array& arr, int index, const std::string& value);
void DeleteArray(Array& arr);
void Print(const Array& arr);
int Length(const Array& arr);
void WriteArrayToFile(const Array& arr, const std::string& filename);
void ReadArrayFromFile(Array& arr, const std::string& filename);