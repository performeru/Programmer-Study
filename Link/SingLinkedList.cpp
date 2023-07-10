#include <iostream>
#include "SingLinkedList.h"


Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* element = new Monster;

    strcpy_s(element->name, NAME_LENGTH, name);
    element->hp = hp;

    if(list.pTail==nullptr)
    {
        list.pHead = element;
    }
    else
    {
        list.pTail->pNext = element;
    }
    list.pTail = element;

    return element;
}

int GetMonsterCount(const MonsterList& list)
{
    Monster* p = list.pHead;
    int count{};

    while(p)
    {
        count++;
        p = p->pNext;

    }
    return count;
}

void PrintMonstersR(Monster* p)
{
    if(p==nullptr)
    {
        return;
    }
    std::cout << p->name << " : " << p->hp << std::endl;
    PrintMonstersR(p->pNext);
}

void PrintMonsters(const MonsterList& list)
{
    PrintMonstersR(list.pHead);
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
    Monster* p = list.pHead;

    while(p)
    {
        if (strcmp(p->name, name) == 0)
        {
            return p;
        }
    }
    return nullptr;
}

void DeleteAll(MonsterList& list)
{
    Monster* p = list.pHead;

    while(p)
    {
        Monster* next = p->pNext;
        delete p;

        p = next;
    }

    list.pHead = list.pTail = nullptr;
}

bool DeleteMonser(MonsterList& list, const char* name)
{
    return false;
}
