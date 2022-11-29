#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    List();
    ~List();

    Node<T> *getHead();
    Node<T> *getTail();
    void setHead(Node<T> *);
    void setTail(Node<T> *);
    int getcount();
    void setcount(int);
    bool IsEmpty();
    int indexOf(const T); //Tim kiem phan tu trung va tra ve vi tri phan tu do
    T SearchID(const string &);
    void AddHead(T data); // thêm vào đầu
    void AddTail(T data);  // thêm vào cuối
    void AddAt(T data, int p); //Them vao vi tri bat ky
    void DeleteHead(); // xóa phần tử đầu
    void DeleteTail(); // xóa phần tử cuối
    bool DeleteHead(const T);
    bool DeleteTail(const T);
    bool DeleteAt(const int &);

    void Show();
    bool Delete(const T); // <- viết
};

template <class T>
List<T>::List()
{
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}
template <class T>
List<T>::~List()
{
    Node<T> *p = this->head;
    while (this->head != this->tail)
    {
        p = this->head;
        this->head = this->head->getNext();
        delete p;
    }
    delete this->tail;
}
template <class T>
Node<T> *List<T>::getHead()
{
    return head;
}

template <class T>
Node<T> *List<T>::getTail()
{
    return tail;
}
template <class T>
void List<T>::setHead(Node<T> *head)
{
    this->head = head;
}
template <class T>
void List<T>::setTail(Node<T> *tail)
{
    this->tail = tail;
}

template <class T>
int List<T>::getcount()
{
    return this->count;
}
template <class T>
void List<T>::setcount(int count)
{
    this->count = count;
}
template <class T>
bool List<T>::IsEmpty()
{
    return this->head == NULL;
}

template <class T>
void List<T>::AddHead(T data)   //Them vao dau
{
    if (this->head == NULL)
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        this->tail = NewNode;
        this->head = NewNode;
        this->count++;
    }
    else
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        NewNode->setNext(head);
        this->head->setPrev(NewNode);
        this->head = NewNode;
        this->count++;
    }
}
template <class T>
void List<T>::AddAt(T data, int p)   
{
    if (this->head == NULL)
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        this->tail = NewNode;
        this->head = NewNode;
        this->count++;
    }
    else
    {
        p = p - 2;
        Node<T> *ptr = this->head;
        while (p != 0)
        {
            ptr = ptr->getNext();
            p--;
        }

        Node<T> *middleNode = new Node<T>;
        middleNode->setData(data);
        middleNode->setNext(ptr->getNext());
        ptr->getNext()->setPrev(middleNode);

        ptr->setNext(middleNode);
        middleNode->setPrev(ptr);

        ptr = head;
    }
}
template <class T>
void List<T>::AddTail(T data)    //Them vao cuoi
{
    if (this->head == NULL)
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        this->tail = NewNode;
        this->head = NewNode;
        this->count++;
    }
    else
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        NewNode->setPrev(tail);
        tail->setNext(NewNode);
        tail = NewNode;
        count++;
    }
}

template <class T>
int List<T>::indexOf(const T e)
{
    int index = 0;
    Node<T> *p = this->getHead();
    while (p != NULL)
    {
        if (p->getData() == e)
            return index;
        index++;
        p = p->getNext();
    }
    return -1;
}

template <class T>
void List<T>::DeleteHead()  // Xoa dau
{
    Node<T> *p = this->head->getNext();
    delete this->head;
    this->setHead(p);
    this->head->setPrev(NULL);
    this->count -= 1;
}
template <class T>
void List<T>::DeleteTail()
{
    Node<T> *p = this->tail->getPrev();
    delete this->tail;
    this->setTail(p);
    this->tail->setNext(NULL);
    this->count -= 1;
}

template <class T>
bool List<T>::DeleteAt(const int &index)
{
    if (index < 0 || index >= this->count)
        return false;
    else
    {
        if (index == 0)
        {
            this->DeleteHead();
            return true;
        }
        if (index == count - 1)
        {
            this->DeleteTail();
            return true;
        }
        int i = 0;
        Node<T> *p = this->head;
        while (i != index)
        {
            i++;
            p = p->getNext();
        }
        Node<T> *temp = p;
        p->getPrev()->setNext(p->getNext());
        p->getNext()->setPrev(p->getPrev());
        this->count -= 1;
        delete temp;
        return true;
    }
}
template <class T>
bool List<T>::Delete(const T e)
{
    int index = this->indexOf(e);
    if (index == -1)
        return false;
    else
    {
        this->DeleteAt(index);
        return true;
    }
}
template <class T>
bool List<T>::DeleteHead(const T e)
{
    this->DeleteHead();
    return true;
}
template <class T>
bool List<T>::DeleteTail(const T e)
{
    this->DeleteTail();
    return true;
}
template <class T>
void List<T>::Show()
{
    Node<T> *ptr = this->head;
    while (ptr != NULL)
    {
        ptr->getData().show();
        ptr = ptr->getNext();
    }
}

template <class T>
T List<T>::SearchID(const string &ID)
{
    Node<T> *ptr = this->head;
    while (ptr != NULL)
    {
        if (ptr->getData().getId() == ID)
            return ptr->getData();
        ptr = ptr->getNext();
    }
    return T();
}
#endif