#include <iostream>
#include <stack>
#include <queue>
using namespace std;



void StackAndQueue()
{
	stack <int> s;

	s.push(1);
	s.push(2);
	s.push(3);


	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}


	queue <int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	q.pop();

	queue<int> temp(q);

	while (!temp.empty())
	{
		cout << temp.front() << " ";
		temp.pop();
	}
	cout << endl;

	priority_queue<int> pq;

	pq.push(3);
	pq.push(6);
	pq.push(1);

	priority_queue<int> temp2(pq);

	while (!temp2.empty())
	{
		cout << temp2.top() << " ";
		temp2.pop();
	}
}
