#include <iostream>
using namespace std;

class Node
{
public:
	int mData;
	Node* mNext;

	Node(int mData) : mData(mData), mNext(nullptr) {}
};

class LinkedList
{
protected:
	Node* mHead;

public:
	LinkedList() : mHead(nullptr) {}

	void Append(int mData)
	{
		Node* node = new Node(mData);
		if(!mHead)
		{
			mHead = node;
		}
		else
		{
			Node* Current = mHead;
			while (Current->mNext)
			{
				Current = Current->mNext;
			}
			Current->mNext = node;
		}
	}

	void PrintList()
	{
		Node* Current = mHead;

		while (Current)
		{
			cout << Current->mData << " -> ";
			Current = Current->mNext;
		}
		cout << "None" << endl;
	}
};

class Stack : public LinkedList
{
public:
	void Push(int data)
	{
		Append(data);
	}

	int Pop()
	{
		if(!mHead)
		{
			return -1;
		}
		else if(!mHead->mNext)
		{
			int data = mHead->mData;
			delete mHead;
			mHead = nullptr;
			return data;
		}
		else 
		{
			Node* Current = mHead;

			while (Current->mNext->mNext)
			{
				Current = Current->mNext;
			}

			int data = Current->mNext->mData;
			delete Current->mNext;
			Current->mNext = nullptr;
			return data;
		}
	}
};

class Queue : public LinkedList
{
public: 
	void EnQueue(int data)
	{
		Append(data);
	}

	int DeQueue()
	{
		if(!mHead)
		{
			return -1;
		}
		int data = mHead->mData;
		Node* temp = mHead;
		mHead = mHead->mNext;
		delete temp;
		return data;
	}
};
