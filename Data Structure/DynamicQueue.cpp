#include <iostream>

struct Element
{
    int value{};
    Element* pNext{};
};

struct Queue
{
    Element* pFront{};
    Element* pRear{};
    int count{};
};

void Enqueue(Queue& queue, int value)
{
    Element* pElement = new Element{};
    pElement->value = value;
    pElement->pNext = nullptr;

    if (queue.count == 0)
    {
        queue.pFront = pElement;
        queue.pRear = pElement;
    }
    else
    {
        queue.pRear->pNext = pElement;
        queue.pRear = pElement;
    }

    queue.count++;
}

void Dequeue(Queue& queue)
{
    if (queue.count == 0)
    {
        std::cout << "QUEUE IS EMPTY" << std::endl;
        return;
    }

    Element* pFront = queue.pFront;
    queue.pFront = pFront->pNext;
    queue.count--;

    delete pFront;
}

void Print(Queue& queue)
{
    Element* pElement = queue.pFront;

    while (pElement)
    {
        std::cout << pElement->value << std::endl;
        pElement = pElement->pNext;
    }
    std::cout << "----------" << std::endl;
}

void DeleteAll(Queue& queue)
{
    Element* pElement = queue.pFront;
    Element* pNext;

    while (pElement)
    {
        pNext = pElement->pNext;
        delete pElement;
        pElement = pNext;
    }

    queue.count = 0;
    queue.pFront = nullptr;
    queue.pRear = nullptr;
}

int main()
{
    Queue queue;

    Enqueue(queue, 30);
    Enqueue(queue, 20);
    Enqueue(queue, 10);
    Print(queue);

    Dequeue(queue);
    Print(queue);

    DeleteAll(queue);
    Print(queue);

    return 0;
}
