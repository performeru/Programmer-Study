#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;



int main()
{
	ofstream fout("test0.txt");
	
	if(!fout)
	{
		cout << "파일을 열수 없습니다" << endl;
		return 1;
	}
	
	const int num{ 5 };

	int test[num];

	cout << "시험점수" << endl;
	cout << num << "명의 점수를 입력하세요" << endl;

	for(int i=0; i<num; i++)
	{
		cin >> test[i];
	}

	for(int j=0; j<num; j++)
	{
		fout << "No." << j + 1 << setw(5) << test[j] << endl;
	}

	fout.close();
	
	cout << "파일을 닫았습니다" << endl;
}
