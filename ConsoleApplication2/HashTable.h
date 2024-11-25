#include <string>

struct NodeH {
    std::string key;
    std::string value;
    NodeH* next;
};

class HashTable {
public:
    static const int tableSize = 10;
    HashTable();
    ~HashTable();

    void insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    void remove(const std::string& key);
    void printTable() const;
    void writeToFile(const std::string& filename) const;
    void readFromFile(const std::string& filename);
    void clear();

private:
    NodeH* table[tableSize];
    int hashFunction(const std::string& key) const;
};