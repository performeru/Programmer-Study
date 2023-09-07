#include <iostream>
#include "DoubleLinkedList.h"


Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
	Monster* element = new Monster;

	strcpy_s(element->name, NAME_LENGTH, name);
	element->hp = hp;
	element->pNext = nullptr;
	element->pPrevious = list.pTail;

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



void PrintMonsters(const MonsterList& list)
{
	Monster* p = list.pHead;

	while (p)
	{
		std::cout << p->name << " : " << p->hp << std::endl;
		p = p->pNext;
	}
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* p = list.pHead;

	while(p)
	{
		if(strcmp(p->name, name)==0)
		{
			return p;
		}
		p = p->pNext;
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
	Monster* p = list.pHead;
	
	while(p)
	{
		if(strcmp(p->name, name)==0)
		{
			if(p->pPrevious)
			{
				p->pPrevious->pNext = p->pNext;
			}
			else
			{
				list.pHead = p->pNext;
			}

			if(p->pNext)
			{
				p->pNext->pPrevious = p->pPrevious;
			}
			else
			{
				list.pTail = p->pPrevious;
			}
			delete p;
			return true;
		}
		p = p->pNext;
	}
	return false;
}
