#include <iostream>
#include <map>
using namespace std;

void Mapex()
{
	struct Student
	{
		int Number;
		int Score;
		string Name;
	};

	map<int, Student> students
	{
		{1,{ 1,100,"Doggy"}},
		{2,{2,50,"Kitty"}},
		{3,{3,90,"Piggy"}},
		{4,{4,30,"Bunny"}}
	};

	students.insert(make_pair<int, Student>(5,{ 5,80,"Duck"}));

	for(auto student: students)
	{
		cout << student.second.Number << " : " << student.second.Name << " , " << student.second.Score << endl;

	}
}
