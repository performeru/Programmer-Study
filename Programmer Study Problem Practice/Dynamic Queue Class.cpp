#include <iostream>

class DynamicQueuekManger
{
private:
    struct Element
    {
        int value{};
        Element* pNext{};
    };

    Element* mpFront{};
    Element* mpRear{};
    int mCount{};

public:
    class DynamicQueuekManger() : mpFront(nullptr), mpRear(nullptr), mCount(0) {}

    void Enqueue(int value)
    {
        Element* pElement = new Element{};
        pElement->value = value;
        pElement->pNext = nullptr;

        if (mCount == 0)
        {
            mpFront = pElement;
            mpRear = pElement;
        }
        else
        {
            mpRear->pNext = pElement;
            mpRear = pElement;
        }

        mCount++;
    }

    void Dequeue()
    {
        if (mCount == 0)
        {
            std::cout << "QUEUE IS EMPTY" << std::endl;
            return;
        }

        Element* pFrontElement = mpFront;
        mpFront = pFrontElement->pNext;
        mCount--;

        delete pFrontElement;
    }

    void Print()
    {
        Element* pElement = mpFront;

        while (pElement)
        {
            std::cout << pElement->value << std::endl;
            pElement = pElement->pNext;
        }
        std::cout << "----------" << std::endl;
    }

    void DeleteAll()
    {
        Element* pElement = mpFront;
        Element* pNext;

        while (pElement)
        {
            pNext = pElement->pNext;
            delete pElement;
            pElement = pNext;
        }

        mCount = 0;
        mpFront = nullptr;
        mpRear = nullptr;
    }
};

int main()
{
    DynamicQueuekManger Queue;

    Queue.Enqueue(30);
    Queue.Enqueue(20);
    Queue.Enqueue(10);
    Queue.Print();

    Queue.Dequeue();
    Queue.Print();

    Queue.DeleteAll();
    Queue.Print();

}
