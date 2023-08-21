#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


char MaxLetter(const string& s)
{
	map<char, int> table;
	char MaxChar{};
	int Max{ -1 };

	for(const auto& e: s)
	{
		table[e]++;

		if(table[e]>Max)
		{
			MaxChar = e;
			Max = table[e];
		}

	}
	return MaxChar;
}
