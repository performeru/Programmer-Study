#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> Numbers;
	int Num{};

	cout << "정수 입력" << endl;

	while (cin >> Num)
	{
		Numbers.push_back(Num);
	}

	vector<int> Vector = Numbers;
	int TotalSum{};

	for(int Num : Numbers)
	{
		TotalSum += Num;
	}

	
	for(int i=0; i<Vector.size(); i++)
	{
		cout << Vector[i] << endl;
	}
	
	cout << "백터의 합계" << TotalSum << endl;
	
}
