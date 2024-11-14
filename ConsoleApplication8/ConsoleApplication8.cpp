#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Структура для узла односвязного списка
struct Node
{
    int numbr;
    Node* next;
};




struct Array {
    string* data; // указатель на массив строк
    int size;
    int capacity; // максимальный размер
};

// создание массива с нужной ёмкостью
void CreateArray(Array& arr, int capac) {
    arr.data = new string[capac];
    arr.size = 0;
    arr.capacity = capac;
}

// добавление элемента в конец массива
void Add(Array& arr, const string& value) {
    if (arr.size == arr.capacity) {
        string* newdata = new string[arr.capacity * 2];
        for (int i = 0; i < arr.size; i++) { // Копирует элементы из старого массива в новый массив.
            newdata[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newdata; // Указатель data структуры Array направляется на новый массив.
        arr.capacity *= 2;
    }
    arr.data[arr.size] = value; // Новый элемент value добавляется в конец массива.
    arr.size++; // Обновляется текущий размер массива.
}

// добавление элемента по индексу
void AddIndex(Array& arr, int index, const string& value) {
    if (index < 0 || index > arr.size) {
        cerr << "index out of array bounds" << endl;
        return;
    }
    if (arr.size >= arr.capacity) {
        string* newdata = new string[arr.capacity * 2];
        for (int i = 0; i < arr.size; i++) {
            newdata[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newdata;
        arr.capacity *= 2;
    }
    for (int i = arr.size; i > index; i--) { // Элементы массива, начиная с индекса arr.size 
        arr.data[i] = arr.data[i - 1]; // и до индекса index, сдвигаются на одну позицию вправо
    }
    arr.data[index] = value;
    arr.size++;
}

// получение элемента по индексу
string Getin(const Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "index out of array bounds" << endl;
        return "";
    }
    return arr.data[index];
}

// удаление элемента по индексу
void Delin(Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "index out of array bounds" << endl;
        return;
    }
    for (int i = index; i < arr.size - 1; i++) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
}

// замена элемента по индексу
void Setin(Array& arr, int index, const string& value) {
    if (index < 0 || index >= arr.size) {
        cerr << "index out of array bounds" << endl;
        return;
    }
    arr.data[index] = value;
}

// освобождение памяти
void DeleteArray(Array& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

// вывод элементов массива
void Print(const Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

// длина массива
int Length(const Array& arr) {
    return arr.size;
}

// запись в файл
void WriteArrayToFile(const Array& arr, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Can't open file" << endl;
        return;
    }
    for (int i = 0; i < arr.size; i++) {
        outFile << arr.data[i] << endl;
    }
    outFile.close();
    cout << "File was written " << filename << endl;
}

// чтение из файла
void ReadArrayFromFile(Array& arr, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Can't open file" << endl;
        return;
    }

    // Очищаем существующий массив
    DeleteArray(arr);

    string value;
    int count = 0;
    while (getline(inFile, value)) { // Чтение строки
        Add(arr, value);
        count++;
    }
    if (count > 0) {
        cout << count << " elements were read" << endl;
    }
    else {
        cout << "File is empty" << endl;
    }

    inFile.close();
    cout << "File was read " << filename << endl;
}





// Структура для узла односвязного списка
struct NodeL
{
    int data;
    NodeL* next;
};

// Добавление элемента в голову списка
void addHeadL(NodeL*& head, int value)
{
    NodeL* newNodeLO = new NodeL; // Создаем новый узел
    newNodeLO->data = value;      // Заполняем его значением
    newNodeLO->next = head;       // Новый узел указывает на текущую голову
    head = newNodeLO;             // Новый узел становится головой
}

// Добавление элемента в хвост списка
void addTailL(NodeL*& head, int value) {
    NodeL* newNodeL = new NodeL; // Создаем новый узел
    newNodeL->data = value;      // Заполняем его значением
    newNodeL->next = nullptr;    // Новый узел будет последним

    if (!head) {                 // Если список пуст
        head = newNodeL;         // Новый узел становится головой
    }
    else {
        NodeL* temp = head;
        while (temp->next) {     // Ищем последний узел
            temp = temp->next;
        }
        temp->next = newNodeL;   // Присоединяем новый узел к хвосту
    }
}

// Удаление элемента с головы списка
void deleteHeadL(NodeL*& head) {
    if (!head) return;           // Если список пуст, ничего не делаем
    NodeL* temp = head;          // Сохраняем указатель на голову
    head = head->next;           // Голова становится следующим узлом
    delete temp;                 // Удаляем старый головной узел
}

// Удаление элемента с хвоста списка
void deleteTailL(NodeL*& head) {
    if (!head) return;           // Если список пуст, ничего не делаем
    if (!head->next) {           // Если в списке один элемент
        delete head;             // Удаляем его
        head = nullptr;          // Обнуляем указатель на голову
        return;
    }
    NodeL* temp = head;
    while (temp->next->next) {   // Ищем предпоследний узел
        temp = temp->next;
    }
    delete temp->next;           // Удаляем последний узел
    temp->next = nullptr;        // Обнуляем указатель на следующий узел
}

// Удаление элемента по значению
bool deleteByValueL(NodeL*& head, int value) {
    if (!head) return false;     // Если список пуст, возвращаем false

    // Проверка, нужно ли удалить голову
    if (head->data == value) {
        deleteHeadL(head);       // Удаляем голову
        return true;             // Удаление успешно
    }

    NodeL* current = head;
    while (current->next && current->next->data != value) {
        current = current->next; // Ищем узел с нужным значением
    }

    // Если значение найдено, удаляем узел
    if (current->next) {
        NodeL* temp = current->next;
        current->next = current->next->next;
        delete temp;             // Освобождаем память
        return true;             // Удаление успешно
    }

    return false;                // Значение не найдено
}

// Поиск элемента по значению
NodeL* searchL(NodeL* head, int value) {
    NodeL* current = head;
    while (current) {
        if (current->data == value) {
            return current;      // Возвращаем узел, если значение найдено
        }
        current = current->next;
    }
    return nullptr;              // Возвращаем nullptr, если значение не найдено
}

// Печать списка
void printListL(NodeL* head) {
    while (head) {
        cout << head->data << " "; // Выводим значение узла
        head = head->next;         // Переходим к следующему узлу
    }
    cout << endl;
}

// Запись списка в файл
void writeToFileL(NodeL* head, const string& filename) {
    ofstream file(filename); // Открываем файл для записи
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    NodeL* temp = head;
    while (temp) {
        file << temp->data << endl; // Записываем значение узла в файл
        temp = temp->next;          // Переходим к следующему узлу
    }
    file.close(); // Закрываем файл
}

// Очистка списка
void clearListL(NodeL*& head) {
    while (head) {
        deleteHeadL(head); // Удаляем узлы по одному
    }
}

// Чтение списка из файла
void readFromFileL(NodeL*& head, const string& filename) {
    ifstream file(filename); // Открываем файл для чтения
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    clearListL(head); // Очищаем список перед загрузкой новых данных

    int value;
    int count = 0;  // Счетчик прочитанных значений
    while (file >> value) {
        addTailL(head, value); // Добавляем значение в конец списка
        count++;
    }
    if (count > 0) {
        cout << count;
    }
    else {
        cout << "Файл пуст или данные неверны.\n";
    }
    file.close(); // Закрываем файл
}

// Структура для узла двусвязного списка
struct NodeLS {
    int data;
    NodeLS* next;
    NodeLS* previous;
};

// Удаление элемента с головы двусвязного списка
void deleteHeadLS(NodeLS*& head, NodeLS*& tail) {
    if (!head) return;           // Если список пуст, ничего не делаем
    NodeLS* temp = head;         // Сохраняем указатель на голову
    head = head->next;           // Голова становится следующим узлом
    if (head) {
        head->previous = nullptr; // Обнуляем указатель на предыдущий узел
    }
    else {
        tail = nullptr;          // Если список стал пустым, обнуляем хвост
    }
    delete temp;                 // Удаляем старый головной узел
}

// Очистка двусвязного списка
void clearListLS(NodeLS*& head, NodeLS*& tail) {
    while (head) {
        deleteHeadLS(head, tail); // Удаляем узлы по одному
    }
}

// Добавление элемента в голову двусвязного списка
void addHeadLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* newNodeLS = new NodeLS; // Создаем новый узел
    newNodeLS->data = value;        // Заполняем его значением
    newNodeLS->next = head;         // Новый узел указывает на текущую голову
    newNodeLS->previous = nullptr;  // Новый узел не имеет предыдущего узла

    if (head) {
        head->previous = newNodeLS; // Обновляем указатель на предыдущий узел
    }
    else {
        tail = newNodeLS;           // Если список был пуст, новый узел становится хвостом
    }
    head = newNodeLS;               // Новый узел становится головой
}

// Добавление элемента в хвост двусвязного списка
void addTailLS(NodeLS*& head, NodeLS*& tail, int value) {
    NodeLS* newNodeLS = new NodeLS; // Создаем новый узел
    newNodeLS->data = value;        // Заполняем его значением
    newNodeLS->next = nullptr;      // Новый узел будет последним

    if (!head) {                    // Если список пуст
        newNodeLS->previous = nullptr;
        head = newNodeLS;           // Новый узел становится головой
        tail = newNodeLS;           // Новый узел также становится хвостом
    }
    else {
        newNodeLS->previous = tail; // Новый узел указывает на текущий хвост
        tail->next = newNodeLS;     // Текущий хвост указывает на новый узел
        tail = newNodeLS;           // Новый узел становится хвостом
    }
}

// Удаление элемента с хвоста двусвязного списка
void deleteTailLS(NodeLS*& head, NodeLS*& tail) {
    if (!tail) return;              // Если список пуст, ничего не делаем
    if (head == tail) {             // Если в списке один элемент
        delete head;                // Удаляем его
        head = nullptr;             // Обнуляем указатель на голову
        tail = nullptr;             // Обнуляем указатель на хвост
        return;
    }
    NodeLS* temp = tail;            // Сохраняем указатель на хвост
    tail = tail->previous;          // Хвост становится предыдущим узлом
    tail->next = nullptr;           // Обнуляем указатель на следующий узел
    delete temp;                    // Удаляем старый хвостовой узел
}

// Удаление элемента по значению из двусвязного списка
bool deleteByValueLS(NodeLS*& head, NodeLS*& tail, int value) {
    if (!head) return false;        // Если список пуст, возвращаем false

    if (head->data == value) {      // Если нужно удалить голову
        deleteHeadLS(head, tail);   // Удаляем голову
        return true;                // Удаление успешно
    }

    NodeLS* current = head;
    while (current && current->data != value) {
        current = current->next;    // Ищем узел с нужным значением
    }

    if (current) {
        if (current->next) {
            current->next->previous = current->previous; // Обновляем указатель на предыдущий узел
        }
        else {
            tail = current->previous; // Обновляем хвост, если удаляем последний элемент
        }
        if (current->previous) {
            current->previous->next = current->next; // Обновляем указатель на следующий узел
        }
        delete current;              // Удаляем узел
        return true;                 // Удаление успешно
    }

    return false;                    // Значение не найдено
}

// Поиск элемента по значению в двусвязном списке
NodeLS* searchLS(NodeLS* head, int value) {
    NodeLS* current = head;
    while (current) {
        if (current->data == value) {
            return current;          // Возвращаем узел, если значение найдено
        }
        current = current->next;
    }
    return nullptr;                  // Возвращаем nullptr, если значение не найдено
}

// Печать двусвязного списка
void printListLS(NodeLS* head) {
    while (head) {
        cout << head->data << " ";   // Выводим значение узла
        head = head->next;           // Переходим к следующему узлу
    }
    cout << endl;
}

// Запись двусвязного списка в файл
void writeToFileLS(NodeLS* head, const string& filename) {
    ofstream file(filename);         // Открываем файл для записи
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    NodeLS* temp = head;
    while (temp) {
        file << temp->data << endl;  // Записываем значение узла в файл
        temp = temp->next;           // Переходим к следующему узлу
    }
    file.close();                    // Закрываем файл
}

// Чтение двусвязного списка из файла
void readFromFileLS(NodeLS*& head, NodeLS*& tail, const string& filename) {
    ifstream file(filename);         // Открываем файл для чтения
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    clearListLS(head, tail);         // Очищаем список перед загрузкой новых данных

    int value;
    int count = 0;
    while (file >> value) {
        addTailLS(head, tail, value); // Добавляем значение в конец списка
        count++;
    }
    if (count > 0) {
        cout << count << " элементов загружено из файла.\n";
    }
    else {
        cout << "Файл пуст или данные неверны.\n";
    }
    file.close();                    // Закрываем файл
}

// Структура для очереди
struct Q
{
    Node* first;
    Node* last;
    Q() : first(nullptr), last(nullptr) {}
};

// Добавление элемента в очередь
void AddQ(Q& queue, int number) {
    Node* newnode = new Node;       // Создаем новый узел
    newnode->numbr = number;        // Заполняем его значением
    newnode->next = nullptr;        // Новый узел будет последним

    if (queue.first == nullptr) {   // Если очередь пуста
        queue.first = newnode;      // Новый узел становится первым
        queue.last = newnode;       // Новый узел также последний
    }
    else {
        queue.last->next = newnode; // Указатель next последнего узла указывает на новый узел
        queue.last = newnode;       // Обновляем указатель на последний узел
    }
}

// Удаление элемента из очереди
void DelQ(Q& queue) {
    if (queue.first == nullptr) {
        cout << "empty queue";      // Если очередь пустая, выводим сообщение
    }

    Node* clr = queue.first;        // Сохраняем указатель на первый узел
    queue.first = queue.first->next;// Убираем первый элемент

    if (queue.first == nullptr) {
        queue.last = nullptr;       // Если очередь стала пустой, обнуляем указатель на последний узел
    }
    delete clr;                     // Освобождаем память
}

// Вывод элементов очереди
void ShowQ(const Q& queue) {
    Node* showtime = queue.first;
    while (showtime) {
        cout << showtime->numbr << endl; // Выводим значение узла
        showtime = showtime->next;       // Переходим к следующему узлу
    }
}

// Структура для стека
struct S
{
    Node* head = nullptr;
};

// Добавление элемента в стек
void AddS(S* stack, const int& data) {
    Node* new_node = new Node{ data, nullptr }; // Создаем новый узел
    new_node->next = stack->head;               // Новый узел указывает на текущую голову
    stack->head = new_node;                     // Новый узел становится головой
}

// Удаление элемента из стека
void DelS(S* stack) {
    if (stack->head == nullptr) {
        cout << "Stack empty" << endl;          // Если стек пустой, выводим сообщение
    }

    Node* new_head = stack->head->next;         // Сохраняем указатель на следующий узел
    delete stack->head;                         // Удаляем текущую голову
    stack->head = new_head;                     // Обновляем указатель на голову
}

// Вывод элементов стека
void ShowS(S* stack) {
    if (stack->head == nullptr) {
        cout << "Stack empty" << endl;          // Если стек пустой, выводим сообщение
    }

    Node* showtime = stack->head;
    while (showtime != nullptr) {
        cout << showtime->numbr << " ";         // Выводим значение узла
        showtime = showtime->next;              // Переходим к следующему узлу
    }
    cout << endl;
}

// Структура для узла хеш-таблицы
struct NodeH {
    string key;
    string value;
    NodeH* next;
};

// Класс хеш-таблицы
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

// Конструктор хеш-таблицы
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

// Добавление элемента в хеш-таблицу
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

// Структура для узла бинарного дерева
struct TNode {
    int key;
    TNode* parent;
    TNode* left;
    TNode* right;

    TNode(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Вставка узла в бинарное дерево
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

// Поиск узла в бинарном дереве
TNode* search(TNode* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }
    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}

// Поиск минимального элемента в бинарном дереве
TNode* minElem(TNode* root) {
    TNode* m = root;
    while (m && m->left != nullptr) {
        m = m->left;
    }
    return m;
}

// Поиск максимального элемента в бинарном дереве
TNode* maxElem(TNode* root) {
    TNode* x = root;
    while (x && x->right != nullptr) {
        x = x->right;
    }
    return x;
}

// Поиск следующего элемента в бинарном дереве
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

// Удаление узла из бинарного дерева
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

// Сохранение бинарного дерева в файл
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

// Загрузка бинарного дерева из файла
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

// Печать бинарного дерева
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

// Подсчет количества узлов в бинарном дереве
int countNodes(TNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Проверка, является ли бинарное дерево полным
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

// Проверка, является ли бинарное дерево полным
bool isCompleteBinaryTree(TNode* root) {
    int numberNodes = countNodes(root);
    return isCompleteBinaryTreeUtil(root, 0, numberNodes);
}

// Обработка команд для работы с массивом
void ArrayCommands(Array& arr) {
    string command;
    while (true) {
        cout << " >> ";
        cin >> command;

        // добавление в конец
        if (command == "AADD") {
            string value;
            cin.ignore(); // игнорируем предыдущий символ новой строки
            getline(cin, value); // считываем строку с пробелами

            bool exists = false;
            for (int i = 0; i < arr.size; i++) {
                if (arr.data[i] == value) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                Add(arr, value);
                WriteArrayToFile(arr, "array.txt");
            }
            else {
                cout << "Value already exists" << endl;
            }
        }
        else if (command == "AADDIN") {
            int index;
            string value;
            cin >> index;
            cin.ignore(); // игнорируем предыдущий символ новой строки
            getline(cin, value); // считываем строку

            if (index >= 0 && index <= Length(arr)) {
                AddIndex(arr, index, value);
                WriteArrayToFile(arr, "array.txt");
            }
            else {
                cout << "Index out of range" << endl;
            }
        }
        else if (command == "AGETIN") {
            int index;
            cin >> index;
            if (index >= 0 && index < Length(arr)) {
                cout << "Element at index " << index << ": " << Getin(arr, index) << endl;
            }
            else {
                cout << "Index out of range" << endl;
            }
        }
        else if (command == "ADELIN") {
            int index;
            cin >> index;
            if (index >= 0 && index < Length(arr)) {
                Delin(arr, index);
                WriteArrayToFile(arr, "array.txt");
            }
            else {
                cout << "Index out of range" << endl;
            }
        }
        else if (command == "ASETIN") {
            int index;
            string value;
            cin >> index;
            cin.ignore(); // игнорируем предыдущий символ новой строки
            getline(cin, value); // считываем строку

            if (index >= 0 && index < Length(arr)) {
                Setin(arr, index, value);
                WriteArrayToFile(arr, "array.txt");
            }
            else {
                cout << "Index out of range" << endl;
            }
        }
        else if (command == "ALEN") {
            cout << "Array size: " << Length(arr) << endl;
        }
        else if (command == "APRINT") {
            Print(arr);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Unknown command" << endl;
        }
    }
}

// Обработка команд для работы с односвязным списком
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

// Обработка команд для работы с двусвязным списком
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

// Запись очереди в файл
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

// Чтение очереди из файла
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

// Обработка команд для работы с очередью
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

// Запись стека в файл
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

// Обработка команд для работы с хеш-таблицей
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

// Обработка команд для работы с бинарным деревом
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

// Освобождение памяти для массива
void Adestroy(Array& arr) {
    delete[] arr.data; // Освобождение памяти, выделенной для массива
    arr.data = nullptr; // Устанавливаем указатель в nullptr
    arr.size = 0; // Обнуляем размер
    arr.capacity = 0; // Обнуляем емкость
}

// Очистка очереди
void ClearQueue(Q& queue) {
    while (queue.first) {            // Пока очередь не пуста
        DelQ(queue);                 // Удаляем элементы
    }
}

// Очистка стека
void ClearStack(S* stack) {
    while (stack->head != nullptr) { // Пока стек не пуст
        DelS(stack); // Удаляем элементы
    }
}

// Очистка бинарного дерева
void clearTree(TNode* root) {
    if (root == nullptr) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

// Основная функция программы
int main() {
    setlocale(LC_ALL, "rus");

    Array arr; // Используем структуру Array вместо указателя
    CreateArray(arr, 10); // Инициализируем массив с начальной емкостью 10
    TNode* root = nullptr; // Бинарное дерево
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



    cout << "Элементы массива: ";
    

    // Освобождение памяти
    

    return 0;
    clearListL(list);
    clearListLS(head, tail);
    ClearQueue(queue);
    ClearStack(&stack);
    hashTable.clearH();
    clearTree(root); // Освобождение памяти для бинарного дерева
}