#include <iostream>

const int QUEUE_Size{ 10 };

enum Command
{
	ENQUEUE=1,
	DEQUEUE=2,
	QUIT=3
};

class QueueManger
{

private:
	int mContainer[QUEUE_Size]{};
	int mHead;
	int mTail;

public:
	QueueManger() : mHead(0), mTail(0) {}

	void PrintInfo()
	{
		std::cout << "-----Queue-----" << std::endl;
		std::cout << "[1] ENQUEUE" << std::endl;
		std::cout << "[2] DEQUEUE" << std::endl;
		std::cout << "[3] QUIT" << std::endl;
	}

	void PirntQueue()
	{
		int i = mHead;

		if(mHead==mTail)
		{
			std::cout << "Empty" << std::endl;
			return;
		}

		while(i != mTail)
		{
			i = (i + 1) % QUEUE_Size;
			std::cout << mContainer[i] << " ";
		}

		std::cout << std::endl <<
			"----------" << std::endl;
	}

	void EnQueue(int value)
	{
		if(mTail+1%QUEUE_Size==mHead)
		{
			std::cout << "Queue is Full" << std::endl;
			return;
		}

		mTail = (mTail + 1) % QUEUE_Size;
		mContainer[mTail] = value;
	}

	void DeQueue()
	{
		if(mHead==mTail)
		{
			std::cout << "Queue is already Empty" << std::endl;
			return;
		}

		mHead = (mHead + 1) % QUEUE_Size;
	}
};

int main()
{
	QueueManger MyQueue;

	MyQueue.PrintInfo();

	int Command{};
	int value{};
	
	while(true)
	{
		MyQueue.PirntQueue();

		std::cout << ">> : ";
		std::cin >> Command;

		switch (Command)
		{
		case ENQUEUE:
			std::cout << "\t입력 값 :";
			std::cin >> value;
			MyQueue.EnQueue(value);
			break;
		case DEQUEUE:
			MyQueue.DeQueue();
			break;
		case QUIT:
			return 0;
		default:
			std::cout << "잘못된 명령입니다." << std::endl;
			break;
		}
	}
}
