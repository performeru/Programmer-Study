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
