#include <iostream>

struct Element
{
    int value{};
    Element* pNext{};
};

struct Stack
{
    Element* pTop{};
    int count{};
};

void Push(Stack& stack, int value)
{
    Element* pElement = new Element{};
    pElement->value = value;

    pElement->pNext = stack.pTop;
    stack.pTop = pElement;
    stack.count++;
}

void Pop(Stack& stack)
{
    if (stack.count == 0)
    {
        std::cout << "STACK IS EMPTY" << std::endl;
        return;
    }

    Element* pPrevTop = stack.pTop;
    stack.pTop = pPrevTop->pNext;
    stack.count--;

    delete pPrevTop;
}

void Print(Stack& stack)
{
    Element* pElement = stack.pTop;

    while (pElement)
    {
        std::cout << pElement->value << std::endl;
        pElement = pElement->pNext;
    }
    std::cout << "----------" << std::endl;
}

void DeleteAll(Stack& stack)
{
    Element* pElement = stack.pTop;
    Element* pNext;

    while (pElement)
    {
        pNext = pElement->pNext;
        delete pElement;
        pElement = pNext;
    }

    stack.count = 0;
    stack.pTop = nullptr;
}

int main()
{
    Stack stack;

    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    Print(stack);

    Pop(stack);
    Print(stack);

    DeleteAll(stack);
    Print(stack);

    return 0;
}
