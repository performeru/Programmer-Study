#include <iostream>

const int Stack_Size{ 10 };

enum Command
{
	PUSH=1,
	POP=2,
	QUIT=3
};

class StackManger
{
private:
	int mTopIndex{-1};
	int mContainer[Stack_Size]{};

public:
	StackManger() : mTopIndex(-1) {}

	void PrintInfo() const
	{
		std::cout << "-----Stack-----" << std::endl;
		std::cout << "[1] PUSH" << std::endl;
		std::cout << "[2] POP" << std::endl;
		std::cout << "[3] QUIT" << std::endl;
		std::cout << "---------------" << std::endl;
	}

	void PrintStack()
	{
		std::cout << "-----Stack-----" << std::endl;
		
		for(int i=mTopIndex; i>=0; i--)
		{
			std::cout << mContainer[i] << std::endl;
		}
		
		std::cout << "---------------" << std::endl;
		std::cout << "번호를 입력하세요" << std::endl;
	}

	void Push(int value)
	{
		if(mTopIndex>=Stack_Size-1)
		{
			std::cout << "Stack is Full" << std::endl;
			return;
		}

		mTopIndex++;
		mContainer[mTopIndex] = value;
	}

	void Pop()
	{
		if(mTopIndex<0)
		{
			std::cout << "Stack is already empty" << std::endl;
			return;
		}

		mTopIndex = mTopIndex - 1;
	}
};


int main()
{
	StackManger MyStcak;

	MyStcak.PrintInfo();

	int Command{};

	while(true)
	{
		MyStcak.PrintStack();

		std::cout << ">> : ";
		std::cin >> Command;

		int value = 0;

		switch (Command)
		{
		case PUSH:
			std::cout << "\t입력 값 : ";
			std::cin >> value;
			MyStcak.Push(value);
			break;
		case POP:
			MyStcak.Pop();
			break;
		case QUIT:
			return 0;
			break;
		default: 
			std::cout << "잘못된 명령입니다" << std::endl;
			break;
		}
	}
}
