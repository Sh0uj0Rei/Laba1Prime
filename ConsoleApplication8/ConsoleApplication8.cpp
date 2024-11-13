#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    int numbr;
    Node* next;
};


// Структура для массива
struct Array {
    int* data;       
    int size;        // Текущий размер массива
    int capacity;    // Максимальная вместимость массива
};
// Инициализация массива с заданной емкостью
void Ainit(Array& arr, int cap) {
    arr.data = new int[cap];
    arr.size = 0;
    arr.capacity = cap;
}
// Добавление элемента в конец массива
void Aappend(Array& arr, int value) {
    if (arr.size >= arr.capacity) {
        // Увеличение емкости массива
        arr.capacity *= 2;
        int* newData = new int[arr.capacity];
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
    }
    arr.data[arr.size++] = value;
}
// Вставка элемента по индексу
void Ainsert(Array& arr, int index, int value) {
    if (index < 0 || index > arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return;
    }
    if (arr.size >= arr.capacity) {
        arr.capacity *= 2;
        int* newData = new int[arr.capacity];
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
    }
    for (int i = arr.size; i > index; --i) {
        arr.data[i] = arr.data[i - 1];
    }
    arr.data[index] = value;
    arr.size++;
}
// Получение элемента по индексу
int Aget(const Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return -1;
    }
    return arr.data[index];
}
// Удаление элемента по индексу
void Aremove(Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return;
    }
    for (int i = index; i < arr.size - 1; ++i) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
}
// Замена элемента по индексу
void Areplace(Array& arr, int index, int value) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl;
        return;
    }
    arr.data[index] = value;
}
// Получение длины массива
int Alength(const Array& arr) {
    return arr.size;
}
// Вывод элементов массива
void printArray(const Array& arr) {
    for (int i = 0; i < arr.size; ++i) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}
void writeToFileArray(const Array& arr, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Не удалось открыть файл для записи." << endl;
        return;
    }
    for (int i = 0; i < arr.size; ++i) {
        file << arr.data[i] << endl;
    }
    file.close();
    cout << "Данные успешно записаны в файл: " << filename << endl;
}

struct NodeL
{
    int data;
    NodeL* next;
};
// Добавление элемента в голову списка
void addHeadL(NodeL*& head, int value)
{
    NodeL* newNodeLO = new NodeL;
    newNodeLO->data = value;
    newNodeLO->next = head;
    head = newNodeLO;
}
// Добавление элемента в хвост списка
void addTailL(NodeL*& head, int value) {
    NodeL* newNodeL = new NodeL;
    newNodeL->data = value;
    newNodeL->next = nullptr;

    if (!head) {
        head = newNodeL;
    }
    else {
        NodeL* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNodeL;
    }
}
// Удаление элемента с головы списка
void deleteHeadL(NodeL*& head) {
    if (!head) return;
    NodeL* temp = head;
    head = head->next;
    delete temp;
}
// Удаление элемента с хвоста списка
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
// Удаление элемента по значению
bool deleteByValueL(NodeL*& head, int value) {
    if (!head) return false; // Если список пуст, вернуть false

    // Проверка, нужно ли удалить голову
    if (head->data == value) {
        deleteHeadL(head); // Предполагается, что deleteHeadLO уже обрабатывает голову
        return true; // Удаление успешно
    }

    NodeL* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    // Если значение найдено, удалить узел
    if (current->next) {
        NodeL* temp = current->next;
        current->next = current->next->next;
        delete temp; // Освобождаем память
        return true; // Удаление успешно
    }

    return false; // Значение не найдено
}
// Поиск элемента по значению
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
// Печать списка
void printListL(NodeL* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
/// Функция для записи списка в файл
void writeToFileL(NodeL* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    NodeL* temp = head;
    while (temp) {
        file << temp->data << endl;
        temp = temp->next;
    }
    file.close();
}
void clearListL(NodeL*& head) {
    while (head) {
        deleteHeadL(head); // Удаляем узлы по одному
    }
}
// Функция для чтения списка из файла
void readFromFileL(NodeL*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    clearListL(head); // Очищаем список перед загрузкой новых данных

    int value;
    int count = 0;  // Счетчик прочитанных значений
    while (file >> value) {
        addTailL(head, value);
        count++;
    }
    if (count > 0) {
        cout << count;
    }
    else {
        cout << "Файл пуст или данные неверны.\n";
    }
    file.close();
}

struct NodeLS {
    int data;
    NodeLS* next;
    NodeLS* previous;
};
void deleteHeadLS(NodeLS*& head, NodeLS*& tail) {
    if (!head) return;
    NodeLS* temp = head;
    head = head->next;
    if (head) {
        head->previous = nullptr;
    }
    else {
        tail = nullptr; // Если список стал пустым, обнуляем хвост
    }
    delete temp;
}
void clearListLS(NodeLS*& head, NodeLS*& tail) {
    while (head) {
        deleteHeadLS(head, tail);
    }
}
// Добавление элемента в голову списка
void addHeadLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* newNodeLS = new NodeLS;
    newNodeLS->data = value;
    newNodeLS->next = head;
    newNodeLS->previous = nullptr;

    if (head) {
        head->previous = newNodeLS;
    }
    else {
        tail = newNodeLS; // Если список был пуст, новый узел становится хвостом
    }
    head = newNodeLS;
}
// Добавление элемента в хвост списка
void addTailLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* newNodeLS = new NodeLS;
    newNodeLS->data = value;
    newNodeLS->next = nullptr;

    if (!head) {
        newNodeLS->previous = nullptr;
        head = newNodeLS;
        tail = newNodeLS; // Если список пуст, новый узел становится и головой, и хвостом
    }
    else {
        newNodeLS->previous = tail;
        tail->next = newNodeLS;
        tail = newNodeLS; // Обновляем хвост
    }
}
// Удаление элемента с хвоста списка
void deleteTailLS(NodeLS*& head, NodeLS*& tail) {
    if (!tail) return;
    if (head == tail) {
        delete head; // Если один элемент в списке
        head = nullptr;
        tail = nullptr;
        return;
    }
    NodeLS* temp = tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete temp;
}
// Удаление элемента по значению
bool deleteByValueLS(NodeLS*& head, NodeLS*& tail, int value) {
    if (!head) return false;

    if (head->data == value) {
        deleteHeadLS(head, tail);
        return true;
    }

    NodeLS* current = head;
    while (current && current->data != value) {
        current = current->next;
    }

    if (current) {
        if (current->next) {
            current->next->previous = current->previous;
        }
        else {
            tail = current->previous; // Обновляем хвост, если удаляем последний элемент
        }
        if (current->previous) {
            current->previous->next = current->next;
        }
        delete current;
        return true;
    }

    return false;
}
// Поиск элемента по значению
NodeLS* searchLS(NodeLS* head, int value) {
    NodeLS* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
// Печать списка
void printListLS(NodeLS* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// Функция для записи списка в файл
void writeToFileLS(NodeLS* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    NodeLS* temp = head;
    while (temp) {
        file << temp->data << endl;
        temp = temp->next;
    }
    file.close();
}
// Функция для чтения списка из файла
void readFromFileLS(NodeLS*& head, NodeLS*& tail, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    clearListLS(head, tail); // Очищаем список перед загрузкой новых данных

    int value;
    int count = 0;
    while (file >> value) {
        addTailLS(head, tail, value);
        count++;
    }
    if (count > 0) {
        cout << count << " элементов загружено из файла.\n";
    }
    else {
        cout << "Файл пуст или данные неверны.\n";
    }
    file.close();
}

struct Q
{
    Node* first;
    Node* last;
    Q() : first(nullptr), last(nullptr) {}
};
void AddQ(Q& queue, int number) {
    Node* newnode = new Node; // Создаем новый узел
    newnode->numbr = number;  // Заполняем его значением
    newnode->next = nullptr;  // Новый узел будет последним

    if (queue.first == nullptr) { // Если очередь пуста
        queue.first = newnode; // Новый узел становится первым
        queue.last = newnode;  // Новый узел также последний
    }
    else {
        queue.last->next = newnode; // Указатель next последнего узла указывает на новый узел
        queue.last = newnode;        // Обновляем указатель на последний узел
    }
}
void DelQ(Q& queue)//ес чо бахни отчистку памяти потомыыыыы
{
    if (queue.first == nullptr)
    {
        cout << "empty queue"; //если очередь пустая, то ошибка
    }

    Node* clr = queue.first;
    //int removed = clr->numbr;

    queue.first = queue.first->next;//убирается элемент

    if (queue.first == nullptr)
    {
        queue.last = nullptr;
    }
    delete clr;
}
void ShowQ(const Q& queue)
{
    Node* showtime = queue.first;
    while (showtime)
    {
        cout << showtime->numbr << endl;
        showtime = showtime->next;
    }
}

struct S
{
    Node* head = nullptr;
};
void AddS(S* stack, const int& data)
{
    Node* new_node = new Node{ data, nullptr };
    new_node->next = stack->head;
    stack->head = new_node;
}
void DelS(S* stack)
{
    if (stack->head == nullptr)
    {
        cout << "Stack empty" << endl;
    }

    Node* new_head = stack->head->next;
    delete stack->head;
    stack->head = new_head;
}
void ShowS(S* stack)
{
    if (stack->head == nullptr)
    {
        cout << "Stack empty" << endl;
    }

    Node* showtime = stack->head;



    while (showtime != nullptr) {
        cout << showtime->numbr << " ";
        showtime = showtime->next;
    }
    cout << endl;
}

struct NodeH {
    string key;
    string value;
    NodeH* next;
};
class Hash {
public:
    static const int tableSize = 10;
    NodeH* table[tableSize];

    Hash();
    void insertH(const string& key, const string& value);
    string getH(const string& key);
    void removeH(const string& key);
    void printTableH();
    void writeToFileH(const string& filename);
    void readFromFileH(const string& filename);
    void clearH();

private:
    int hashFunction(const string& key); // Объявление хеш-функции
};
Hash::Hash() {
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr; // Инициализируем массив нулями
    }
}
// Хеш-функция
int Hash::hashFunction(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash += ch; // Суммируем ASCII значения символов
    }
    return hash % tableSize; // Возвращаем индекс в пределах размера таблицы
}
// Добавление элемента
void Hash::insertH(const string& key, const string& value) {
    int index = hashFunction(key);
    NodeH* newNode = new NodeH{ key, value, nullptr };

    if (!table[index]) {
        table[index] = newNode; // Если ячейка пуста, добавляем новый узел
    }
    else {
        NodeH* current = table[index];
        while (current) {
            if (current->key == key) {
                current->value = value; // Обновляем значение, если ключ уже существует
                delete newNode; // Удаляем временный узел
                return;
            }
            if (!current->next) {
                current->next = newNode; // Добавляем новый узел в конец цепочки
                return;
            }
            current = current->next;
        }
    }
}
// Получение значения по ключу
string Hash::getH(const string& key) {
    int index = hashFunction(key);
    NodeH* current = table[index];
    while (current) {
        if (current->key == key) {
            return current->value; // Возвращаем значение, если ключ найден
        }
        current = current->next;
    }
    return "Ключ не найден"; // Если ключ не найден
}
// Удаление элемента по ключу
void Hash::removeH(const string& key) {
    int index = hashFunction(key);
    NodeH* current = table[index];
    NodeH* previous = nullptr;

    while (current) {
        if (current->key == key) {
            if (previous) {
                previous->next = current->next; // Удаляем узел из цепочки
            }
            else {
                table[index] = current->next; // Если это первый узел
            }
            delete current; // Освобождаем память
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Ключ не найден для удаления" << endl; // Если ключ не найден
}
// Вывод всех элементов хеш-таблицы
void Hash::printTableH() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i]) {
            NodeH* current = table[i];
            while (current) {
                cout << "{" << current->key << ": " << current->value << "} ";
                current = current->next;
            }
            cout << endl;
        }
    }
}
// Запись хеш-таблицы в файл
void Hash::writeToFileH(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    for (int i = 0; i < tableSize; i++) {
        NodeH* current = table[i];
        while (current) {
            file << current->key << " " << current->value << endl;
            current = current->next;
        }
    }

    file.close();
}
// Чтение хеш-таблицы из файла
void Hash::readFromFileH(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    clearH(); // Очищаем таблицу перед загрузкой новых данных

    string key, value;
    while (file >> key >> value) {
        insertH(key, value);
    }

    file.close();
}
// Освобождение памяти вручную
void Hash::clearH() {
    for (int i = 0; i < tableSize; i++) {
        NodeH* current = table[i];
        while (current) {
            NodeH* temp = current;
            current = current->next;
            delete temp; // Освобождаем память
        }
        table[i] = nullptr; // Обнуляем указатели
    }
}

struct TNode {
    int key;
    TNode* parent;
    TNode* left;
    TNode* right;

    TNode(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};
TNode* insert(TNode* root, int key) {
    if (root == nullptr) {
        return new TNode(key);
    }

    TNode* current = root;
    TNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    TNode* newNode = new TNode(key);
    newNode->parent = parent;
    if (key < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return root; // Возвращаем корень
}
TNode* search(TNode* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }
    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}
TNode* minElem(TNode* root) {
    TNode* m = root;
    while (m && m->left != nullptr) {
        m = m->left;
    }
    return m;
}
TNode* maxElem(TNode* root) {
    TNode* x = root;
    while (x && x->right != nullptr) {
        x = x->right;
    }
    return x;
}
TNode* next(TNode* root) {
    if (root->right != nullptr) {
        return minElem(root->right);
    }
    TNode* p = root->parent;
    while (p != nullptr && root == p->right) {
        root = p;
        p = p->parent;
    }
    return p;
}
TNode* del(TNode* root, int key) {
    TNode* l = search(root, key);
    if (l == nullptr) {
        return root; // Ключ не найден
    }

    // Case 1: No child
    if (l->left == nullptr && l->right == nullptr) {
        if (l->parent) {
            if (l == l->parent->left) {
                l->parent->left = nullptr;
            }
            else {
                l->parent->right = nullptr;
            }
        }
        else {
            // Если l был корнем
            root = nullptr;
        }
        delete l;
    }
    // Case 2: One child
    else if (l->left == nullptr || l->right == nullptr) {
        TNode* child = (l->left != nullptr) ? l->left : l->right;
        if (l->parent) {
            if (l == l->parent->left) {
                l->parent->left = child;
            }
            else {
                l->parent->right = child;
            }
        }
        else {
            // Если l был корнем
            root = child;
        }
        child->parent = l->parent; // Обновляем родителя у дочернего узла
        delete l;
    }
    // Case 3: Two children
    else {
        TNode* m = minElem(l->right); // Находим следующий элемент
        l->key = m->key; // Копируем ключ
        root = del(root, m->key); // Удаляем m из дерева
    }

    return root;
}
void saveBinaryTreeToFile(TNode* root, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем в режиме добавления
    if (!file) {
        std::cerr << "Error: Could not open file for writing\n";
        return;
    }
    if (root) {
        file << root->key << std::endl;
        saveBinaryTreeToFile(root->left, filename);
        saveBinaryTreeToFile(root->right, filename);
    }
}
void loadBinaryTreeFromFile(TNode** root, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file for reading\n";
        return;
    }
    int key;
    while (file >> key) {
        *root = insert(*root, key);
    }
}
void printBinaryTree(TNode* root, int space = 0) {
    if (root == nullptr) {
        return;
    }
    space += 5;
    printBinaryTree(root->right, space);
    std::cout << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->key << std::endl;
    printBinaryTree(root->left, space);
}
int countNodes(TNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCompleteBinaryTreeUtil(TNode* root, int index, int numberNodes) {
    if (root == nullptr) {
        return true;
    }

    // Если индекс узла больше или равен количеству узлов, дерево не полное
    if (index >= numberNodes) {
        return false;
    }

    // Проверяем для левого и правого поддерева
    return isCompleteBinaryTreeUtil(root->left, 2 * index + 1, numberNodes) &&
        isCompleteBinaryTreeUtil(root->right, 2 * index + 2, numberNodes);
}
bool isCompleteBinaryTree(TNode* root) {
    int numberNodes = countNodes(root);
    return isCompleteBinaryTreeUtil(root, 0, numberNodes);
}




void ArrayCommands(Array& arr) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        // Приводим команду к нижнему регистру
        for (auto& c : command) c = tolower(c);

        if (command == "append") {
            int value;
            cin >> value;

            bool exists = false;
            for (int i = 0; i < arr.size; ++i) {
                if (arr.data[i] == value) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                Aappend(arr, value);
                writeToFileArray(arr, "ARRAY.txt");
            }
            else {
                cout << "Значение уже существует." << endl;
            }
        }
        else if (command == "ainsert") {
            int index, value;
            cin >> index >> value;
            if (index >= 0 && index <= Alength(arr)) {
                Ainsert(arr, index, value);
                writeToFileArray(arr, "ARRAY.txt");
            }
            else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "aget") {
            int index;
            cin >> index;
            if (index >= 0 && index < Alength(arr)) {
                cout << "Элемент по индексу " << index << ": " << Aget(arr, index) << endl;
            }
            else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "aremov") {
            int index;
            cin >> index;
            if (index >= 0 && index < Alength(arr)) {
                Aremove(arr, index);
                writeToFileArray(arr, "ARRAY.txt");
            }
            else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "areplace") {
            int index, value;
            cin >> index >> value;
            if (index >= 0 && index < Alength(arr)) {
                Areplace(arr, index, value);
                writeToFileArray(arr, "ARRAY.txt");
            }
            else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "asize") {
            cout << "Длина массива: " << Alength(arr) << endl;
        }
        else if (command == "print") {
            printArray(arr);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Неизвестная команда." << endl;
        }
    }
}

void ListCommands(NodeL*& list, const string& filename) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "LOADDHEAD") {
            int value;
            cin >> value;
            addHeadL(list, value);
            writeToFileL(list, filename);
        }
        else if (command == "LOADDTAIL") {
            int value;
            cin >> value;
            addTailL(list, value);
            writeToFileL(list, filename);
        }
        else if (command == "LODELHEAD") {
            if (list) {
                deleteHeadL(list);
                writeToFileL(list, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LODELTAIL") {
            if (list) {
                deleteTailL(list);
                writeToFileL(list, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LODELVAL") {
            int value;
            cin >> value;
            if (deleteByValueL(list, value)) {
                writeToFileL(list, filename);
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LOSEARCH") {
            int value;
            cin >> value;
            if (searchL(list, value)) {
                cout << "Значение найдено." << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LOPRINT") {
            cout << "Список: ";
            printListL(list);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void DoubleLinkedListCommands(NodeLS*& head, NodeLS*& tail, const string& filename) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "LSADDHEAD") {
            int value;
            cin >> value;
            addHeadLS(head, tail, value);
            writeToFileLS(head, filename);
        }
        else if (command == "LSADDTAIL") {
            int value;
            cin >> value;
            addTailLS(head, tail, value);
            writeToFileLS(head, filename);
        }
        else if (command == "LSDELHEAD") {
            if (head) {
                deleteHeadLS(head, tail);
                writeToFileLS(head, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LSDELTAIL") {
            if (tail) {
                deleteTailLS(head, tail);
                writeToFileLS(head, filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LSDELVAL") {
            int value;
            cin >> value;
            if (deleteByValueLS(head, tail, value)) {
                writeToFileLS(head, filename);
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LSSEARCH") {
            int value;
            cin >> value;
            if (searchLS(head, value)) {
                cout << "Значение найдено." << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LSPRINT") {
            cout << "Список: ";
            printListLS(head);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void writeToFileQ(const Q& queue, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    Node* current = queue.first;
    while (current) {
        file << current->numbr << endl;
        current = current->next;
    }
    file.close();
}
void readFromFileQ(Q& queue, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    int value;
    while (file >> value) {
        AddQ(queue, value);
    }
    file.close();
}
void QueueCommands(Q& queue) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "QPUSH") {
            int value;
            cin >> value;
            AddQ(queue, value);          // Добавляем в очередь
            writeToFileQ(queue, "QUEUE.txt"); // Сохраняем в файл
        }
        else if (command == "QPOP") {
            DelQ(queue);                 // Удаляем из очереди
            writeToFileQ(queue, "QUEUE.txt"); // Сохраняем изменения
        }
        else if (command == "QPRINT") {
            cout << "Очередь: ";
            ShowQ(queue);                // Печатаем очередь
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void writeToFileS(S* stack, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    Node* current = stack->head; // Начинаем с верхнего узла
    while (current) {
        file << current->numbr << endl; // Записываем данные узла в файл
        current = current->next;         // Переход к следующему узлу
    }
    file.close();
}
// Чтение стека из файла
void readFromFileS(S* stack, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    int value;
    while (file >> value) {
        AddS(stack, value); // Добавляем элементы в стек
    }
    file.close();
}
// Обработка команд для работы со стеком
void StackCommands(S* stack) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "SPUSH") {
            int value;
            cin >> value;                  // Читаем значение
            AddS(stack, value);           // Добавляем в стек
            writeToFileS(stack, "STACK.txt"); // Сохраняем в файл
        }
        else if (command == "SPOP") {
            if (stack->head != nullptr) {
                DelS(stack); // Удаляем из стека
                writeToFileS(stack, "STACK.txt"); // Сохраняем изменения
            }
            else {
                cout << "Стек пуст." << endl;
            }
        }
        else if (command == "SPRINT") {
            cout << "Стек: ";
            ShowS(stack); // Печатаем стек
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void HashCommands(Hash& hashTable) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "HINSERT") {
            string key, value;
            cin >> key >> value; // Читаем ключ и значение
            hashTable.insertH(key, value); // Вставляем в хеш-таблицу
            hashTable.writeToFileH("Hash.txt"); // Сохраняем в файл
        }
        else if (command == "HGET") {
            string key;
            cin >> key; // Читаем ключ
            string result = hashTable.getH(key); // Получаем значение
            if (!result.empty()) {
                cout << "Значение: " << result << endl; // Печатаем значение
            }
            else {
                cout << "Значение не найдено." << endl; // Если значение не найдено
            }
        }
        else if (command == "HREMOVE") {
            string key;
            cin >> key; // Читаем ключ
            hashTable.removeH(key); // Удаляем элемент
            hashTable.writeToFileH("Hash.txt"); // Сохраняем изменения
        }
        else if (command == "HPRINT") {
            cout << "Хеш-таблица:" << endl;
            hashTable.printTableH(); // Печатаем таблицу
        }
        else if (command == "EXIT") {
            break; // Выход из программы
        }
        else {
            cout << "Неизвестная команда.\n"; // Если команда не распознана
        }
    }
}

void BinaryTreeCommands(TNode*& root) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "BININSERT") {
            int value;
            cin >> value;
            root = insert(root, value); // Вставка узла
            saveBinaryTreeToFile(root, "BinaryTree.txt"); // Сохранение в файл
        }
        else if (command == "BINDEL") {
            int value;
            cin >> value;
            root = del(root, value); // Удаление узла
            saveBinaryTreeToFile(root, "BinaryTree.txt"); // Сохранение в файл
        }
        else if (command == "BINSEARCH") {
            int value;
            cin >> value;
            if (search(root, value)) {
                cout << "Значение " << value << " найдено." << endl;
            }
            else {
                cout << "Значение " << value << " не найдено." << endl;
            }
        }
        else if (command == "BINMIN") {
            TNode* minNode = minElem(root);
            if (minNode) {
                cout << "Минимальное значение: " << minNode->key << endl;
            }
            else {
                cout << "Дерево пусто." << endl;
            }
        }
        else if (command == "BINMAX") {
            TNode* maxNode = maxElem(root);
            if (maxNode) {
                cout << "Максимальное значение: " << maxNode->key << endl;
            }
            else {
                cout << "Дерево пусто." << endl;
            }
        }
        else if (command == "PRINT") {
            cout << "Дерево:" << endl;
            printBinaryTree(root); // Печать дерева
        }
        else if (command == "ISCOMP") {
            if (isCompleteBinaryTree(root)) {
                cout << "Дерево является полным." << endl;
            }
            else {
                cout << "Дерево не является полным." << endl;
            }
        }
        else if (command == "EXIT") {
            break; // Выход из программы
        }
        else {
            cout << "Неизвестная команда.\n"; // Обработка некорректной команды
        }
    }
}

void Adestroy(Array& arr) {
    delete[] arr.data; // Освобождение памяти, выделенной для массива
    arr.data = nullptr; // Устанавливаем указатель в nullptr
    arr.size = 0; // Обнуляем размер
    arr.capacity = 0; // Обнуляем емкость
}
void ClearQueue(Q& queue) {
    while (queue.first) {            // Пока очередь не пуста
        DelQ(queue);                 // Удаляем элементы
    }
}
void ClearStack(S* stack) {
    while (stack->head != nullptr) { // Пока стек не пуст
        DelS(stack); // Удаляем элементы
    }
}
void clearTree(TNode* root) {
    if (root == nullptr) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int main() {
    setlocale(LC_ALL, "rus");

    Array arr; // Using Array structure instead of pointer
    Ainit(arr, 10); // Initialize array with initial capacity of 10
    TNode* root = nullptr; // дерево
    Hash hashTable;
    NodeL* list = nullptr; // Односвязный список
    NodeLS* head = nullptr; // Двусвязный список
    NodeLS* tail = nullptr; // Хвост двусвязного списка
    Q queue;
    S stack;

    // Основной цикл обработки команд
    while (true) {
        string command;
        cout << ">> ";
        cin >> command;

        if (command == "ARRAY") {
            ArrayCommands(arr);
        }
        else if (command == "HASH") {
            HashCommands(hashTable);
        }
        else if (command == "LO") {
            ListCommands(list, "LISTONE.txt");
        }
        else if (command == "LS") {
            DoubleLinkedListCommands(head, tail, "LISTSEC.txt");
        }
        else if (command == "QUEUE") {
            QueueCommands(queue);
        }
        else if (command == "STACK") {
            StackCommands(&stack);
        }
        else if (command == "TREE") {
            BinaryTreeCommands(root);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда. Попробуйте снова." << endl;
        }
    }

    //Очистка памяти
    Adestroy(arr);
    clearListL(list);
    clearListLS(head, tail);
    ClearQueue(queue);
    ClearStack(&stack);
    hashTable.clearH();
    clearTree(root); // Освобождение памяти для бинарного дерева
}