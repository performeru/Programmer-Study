#pragma once

const int NAME_LENGTH{ 10 };

struct Monster
{
	char name[NAME_LENGTH]{};
	int hp{};

	Monster* pNext{};
};
