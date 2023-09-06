#include <iostream>

const int Stack_Size{ 10 };

enum Command
{
    PUSH = 1,
    POP = 2,
    QUIT = 3
};

struct Stack
{
    int container[Stack_Size]{};
    int topIndex{ -1 };
};

void PrintInfo()
{
    std::cout << "Stack" << std::endl;
    std::cout << "[1] Push" << std::endl;
    std::cout << "[2] pop" << std::endl;
    std::cout << "[3] quit" << std::endl;
    std::cout << "_______________" << std::endl;
}

void PrintStack(Stack& stack)
{
    std::cout << "_____stack_____" << std::endl;

    for (int i = stack.topIndex; i >= 0; i--)
    {
        std::cout << stack.container[i] << std::endl;
    }

    std::cout << "_____________________" << std::endl;
}

void Push(Stack& stack, int value)
{
    if (stack.topIndex >= Stack_Size - 1)
    {
        std::cout << "Stack is FULL" << std::endl;
        return;
    }

    stack.topIndex++;
    stack.container[stack.topIndex] = value;
}

void Pop(Stack& stack)
{
    if (stack.topIndex < 0)
    {
        std::cout << "Stack is already empty" << std::endl;
        return;
    }

    stack.topIndex = stack.topIndex - 1;
}

int main()
{
    Stack myStack;

    PrintInfo();

    int command{};

    while (true)
    {
        PrintStack(myStack);

        std::cout << "> ";
        std::cin >> command;

        switch (command)
        {
        case PUSH:
        {
            int value = 0;
            std::cout << "\tinput value: ";
            std::cin >> value;
            Push(myStack, value);
            break;
        }
        case POP:
            Pop(myStack);
            break;
        case QUIT:
            return 0;
        default:
            std::cout << "잘못된 명령입니다." << std::endl;
            break;
        }
    }

    return 0;
}

