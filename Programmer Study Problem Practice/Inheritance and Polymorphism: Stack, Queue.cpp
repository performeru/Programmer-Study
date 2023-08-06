#include <iostream>

class Node 
{
public:
    int mData;
    Node* next;

    Node(int data) : mData(data), next(nullptr) {}
};

class LinkedList 
{
protected:
    Node* mHead;

public:
    LinkedList() : mHead(nullptr) {}

    ~LinkedList() 
    {
        Node* current = mHead;
        while (current) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void append(int data) 
    {
        Node* new_node = new Node(data);
        if (!mHead) 
        {
            mHead = new_node;
        }
        else 
        {
            Node* current = mHead;
            while (current->next) 
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void printList() 
    {
        Node* current = mHead;
        while (current) {
            std::cout << current->mData << " -> ";
            current = current->next;
        }
        std::cout << "None" << std::endl;
    }
};

class Stack : public LinkedList 
{
public:
    void push(int data)
    {
        append(data);
    }

    int pop() 
    {
        if (!mHead)
        {
            return -1; 
        }
        else if (!mHead->next)
        {
            int data = mHead->mData;
            delete mHead;
            mHead = nullptr;
            return data;
        }
        else 
        {
            Node* current = mHead;
            while (current->next->next) 
            {
                current = current->next;
            }
            int data = current->next->mData;
            delete current->next;
            current->next = nullptr;
            return data;
        }
    }
};

class Queue : public LinkedList 
{
public:
    void enqueue(int data) 
    {
        append(data);
    }

    int dequeue() 
    {
        if (!mHead) 
        {
            return -1; 
        }
        int data = mHead->mData;
        Node* temp = mHead;
        mHead = mHead->next;
        delete temp;
        return data;
    }
};

