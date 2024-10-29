#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int numbr;
    Node* next;
};
struct NodeM
{
    string data;
    NodeM* next;
    NodeM* previous;
};

struct NodeL
{
    int data;
    NodeL* next;
    NodeL* previous;
};

void Add1M(NodeM*& head, string data)//в конец
{
    NodeM* newM = new NodeM;
    newM->data = data;
    newM->next = nullptr;
    newM->previous = nullptr;

    if (!head) {
        head = newM;
    }
    else {
        NodeM* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newM;
        newM->previous = temp;
    }
}

void AddBigMac(NodeM*& head,int index, string data)// по индексу(типо индекс бигмака)
{
    
}

void showM(NodeM* head)
{
    NodeM* temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp=temp->next;
    }
}
void sizeM(NodeM* head)
{
    int size = 0;
    NodeM* temp = head;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    cout << size;
}
void swapM(NodeM* head, int index,string data)
{
    NodeM* temp = head;
    bool valid = 0;
    if (index < 0)
    {
        valid = 0;
    }
    for (int i = 0; i < index; i++)
    {
        if (!temp)
        {
            valid = 0;
        }
        else
        {
            valid = 1;
        }
    }
    if (valid==0)
    {
        cout << "invalid index";
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }
}



struct L
{

};


struct Q
{
    Node* first;
    Node* last;
};
void AddQ(Q& queue, int number)
{
    Node* newnode = new Node;
    newnode->numbr = number;
    newnode->next = nullptr;
    if (queue.first==nullptr) //вот тут кароч мы в войд передаем ссылку на значение и его прям меняем, если пусто
    {
        queue.first = newnode;
        queue.last = newnode;
    }
    else
    {
        queue.first->next = newnode;//в конце добавляем
        queue.last = newnode;//апдейт указателя конца
    }

}
void DelQ(Q& queue)//ес чо бахни отчистку памяти потомыыыыы
{
    if (queue.first==nullptr)
    {
        cout << "empty queue"; //если очередь пустая, то ошибка
    }

    Node* clr = queue.first;
    //int removed = clr->numbr;

    queue.first = queue.first->next;//убирается элемент

    if (queue.first==nullptr)
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


struct H
{

};
struct T
{

};