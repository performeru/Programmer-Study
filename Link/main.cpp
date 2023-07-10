#include <iostream>
#include "SingLinkedList.h"

int main()
{
	MonsterList Mylist;

	CreateMonster(Mylist, "Demon", 100);
	CreateMonster(Mylist, "Wolf", 50);
	CreateMonster(Mylist, "Slime", 10);

	PrintMonsters(Mylist);
	PrintMonstersR(Mylist.pHead);
	std::cout << GetMonsterCount(Mylist) << std::endl;

	Monster* pResult = FindMonster(Mylist,"Demon");
	if(pResult)
	{
		std::cout << pResult->name << "Found!" << std::endl;
	}
	else
	{
		std::cout << "Not Found" << std::endl;
	}
	DeleteAll(Mylist);
}
