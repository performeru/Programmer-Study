#include <iostream>

const int QUEUE_Size{ 10 };

enum Command
{
    ENQUEUE = 1,
    DEQUEUE = 2,
    QUIT = 3
};

struct Queue
{
    int container[QUEUE_Size]{};
    int head{};
    int tail{};
};

void PrintInfo()
{
    std::cout << "Queue" << std::endl;
    std::cout << "[1] Enqueue" << std::endl;
    std::cout << "[2] Dequeue" << std::endl;
    std::cout << "[3] Quit" << std::endl;
}

void PrintQueue(Queue& queue)
{
    int i = queue.head;

    if (queue.head == queue.tail)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    while (i != queue.tail)
    {
        i = (i + 1) % QUEUE_Size;
        std::cout << queue.container[i] << " ";
    }
    std::cout << std::endl << 
        "________________" << std::endl;
}

void EnQueue(Queue& queue, int value)
{
    if ((queue.tail + 1) % QUEUE_Size == queue.head)
    {
        std::cout << "Queue is FULL" << std::endl;
        return;
    }

    queue.tail = (queue.tail + 1) % QUEUE_Size;
    queue.container[queue.tail] = value;
}

void DeQueue(Queue& queue)
{
    if (queue.head == queue.tail)
    {
        std::cout << "Queue is already Empty" << std::endl;
        return;
    }

    queue.head = (queue.head + 1) % QUEUE_Size;
}

int main()
{
    Queue myQueue;

    PrintInfo();

    int command{};
    while (true)
    {
        PrintQueue(myQueue);

        std::cout << "> ";
        std::cin >> command;

        switch (command)
        {
        case ENQUEUE:
        {
            int value;
            std::cout << "\tvalue: ";
            std::cin >> value;
            EnQueue(myQueue, value);
            break;
        }
        case DEQUEUE:
            DeQueue(myQueue);
            break;
        case QUIT:
            return 0;
        default:
            std::cout << "잘못된 명령입니다." << std::endl;
            break;
        }
    }
}
