#include <iostream>
using namespace std;

struct Node
{
    int numbr;
    Node* next;
};

struct M
{

};
struct L
{

};


struct Q
{
    Node* first;
    Node* last;
};
void Add(Q& queue, int number)
{
    Node* newnode = new Node;
    newnode->numbr = number;
    newnode->next = nullptr;
    if (!queue.first) //вот тут кароч мы в войд передаем ссылку на значение и его прям меняем, если пусто
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


struct S
{

};
struct H
{

};
struct T
{

};