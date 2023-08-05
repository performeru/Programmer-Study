#include <iostream>

class DynamicStackManger
{
private:
	struct MyElement
	{
		int value{};
		MyElement* pNext{};
	};

	MyElement* mTop;
	int mCount;

public:
	DynamicStackManger() : mTop(), mCount() {}

	~DynamicStackManger()
	{
		DeleteAll();
	}

	void Push(int value)
	{
		MyElement* pElement = new MyElement;
		pElement->value = value;

		pElement->pNext = mTop;
		mTop = pElement;
		mCount++;
	}
	void Pop()
	{
		if(mCount==0)
		{
			std::cout << "Stack is Empty" << std::endl;
			return;
		}

		MyElement* pPrevTop = mTop;
		mTop = mTop->pNext;
		mCount--;

		delete pPrevTop;
	}

	void Print()
	{
		MyElement* pElement = mTop;

		while(pElement)
		{
			std::cout << pElement->value << std::endl;
			pElement = pElement->pNext;
		}
		std::cout << "----------" << std::endl;
	}

	void DeleteAll()
	{
		MyElement* pElement = mTop;
		MyElement* pNext;

		while (pElement)
		{
			pNext = pElement->pNext;
			delete pElement;
			pElement = pNext;
		}

		mCount = 0;
		mTop = nullptr;
	}

};

int main()
{
	DynamicStackManger stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	
	stack.Print();

	stack.Pop();
	stack.Print();

	stack.DeleteAll();
	stack.Print();
}
