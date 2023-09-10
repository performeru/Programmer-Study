#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream fin("test1.txt");
	
	if(!fin)
	{
		cout << "파일을 열수 없습니다" << endl;
		return 1;
	}
	
	const int num{ 8 };
	
	int test[num];

	for(int i=0; i<num; i++)
	{
		fin >> test[i];
	}
	int max = test[0];
	int min = test[0];

	for(int j=0; j<num; j++)
	{
		if(max<test[j])
		{
			max = test[j];
		}
		if(min>test[j])
		{
			min = test[j];
		}
		cout << "No." << j + 1 << setw(5) << test[j] << endl;
	}

	cout << "가장 높은 점수는" << max << endl;
	cout << "가장 낮은 점수는" << min << endl;

	fin.close();
	
	cout << "파일을 닫았습니다" << endl;
}
