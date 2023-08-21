#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IS_SameImange(string s, string t)
{
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	return s == t;
}

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
