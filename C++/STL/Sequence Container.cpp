#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
using namespace std;

void ArrayEx()
{
	array<int, 4> MyArray{1, 2, 3, 4};

	for(const auto& e : MyArray)
	{
		cout << e << " ";
	}
	cout << endl;

	for(array<int, 4>::iterator itr = MyArray.begin(); itr!=MyArray.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;

	for(int i=0; i<MyArray.size(); i++)
	{
		cout << MyArray[i] << " ";
	}
	cout << endl;

	sort(MyArray.begin(), MyArray.end());
	[[maybe_unused]] auto minValue = min_element(MyArray.begin(), MyArray.end());
}

void VectorEx()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.pop_back();
	v.resize(100);

	sort(v.begin(), v.end());
}

void ForwardListEx()
{
	forward_list <int> list  {10, 11, 1, 2};

	list.push_front(1);
	list.pop_front();

	list.sort();

	for(const auto& e : list)
	{
		cout << e << " ";
	}
	cout << endl;
}

void ListEx()
{
	list <int> list {10, 11, 1, 2};

	list.push_front(1);
	list.push_back(100);
	list.pop_front();
	list.pop_back();

	list.sort();

	for(const auto& e : list)
	{
		cout << e << " ";
	}
	cout << endl;
}

void DequeEx()
{
	deque<int> deq{3, 4, 5};

	deq.push_front(1);
	deq.push_back(6);

	deq.pop_front();
	deq.pop_back();

	sort(deq.begin(), deq.end());

	for(const auto& e : deq)
	{
		cout << e << " ";
	}
	cout << endl;
}
