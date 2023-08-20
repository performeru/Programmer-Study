#include <iostream>
#include <vector>
using namespace std;


class Students
{
public:
	int mNumber;
	string mName;
	int mScore;

public:
	void Print() const
	{
		cout << "[" << mNumber << "]" << mName << " : " << mScore << endl;
	}
};

void AddStudnet(vector<Students>& v)
{
	cout << "번호, 이름, 점수 입력 " << endl;

	Students NewStudnet;

	if(cin >> NewStudnet.mNumber >> NewStudnet.mName >> NewStudnet.mScore)
	{
		auto itr=find_if(v.begin(), v.end(), [&](const auto& e) {return e.mNumber == NewStudnet.mNumber; });
		if (itr != v.end())
		{
			cout << "중복된 번호 입니다" << endl;
		}
		v.push_back(NewStudnet);
	}
	else
	{
		cout << "잘못된 입력입니다" << endl;
	}
}

void RemoveStudent(vector<Students>& v)
{
	cout << "삭제할 번호를 입력하세요" << endl;
	
	int number;

	if(cin >> number)
	{
		v.erase(remove_if(v.begin(), v.end(), [&](auto& e) {return e.mNumber == number; }));
	}
	else
	{
		cout << "번호를 입력하세요" << endl;
	}
}

void PrintStudnet(vector<Students>& v)
{
	for(const auto& e : v)
	{
		e.Print();
	}
}

void PrintAverage(vector<Students>& v)
{
	int total{};

	for(const auto& e : v)
	{
		total += e.mScore;
	}

	cout << "총점 : " << total << ", 평균 : " << total / v.size() << endl;
}

void PrintOverAverage(vector<Students>& v)
{
	int total{};

	for(const auto& e : v)
	{
		total += e.mScore;
	}

	int average = total / static_cast<int>(v.size());

	for(const auto& e : v)
	{
		if(e.mScore >= average)
		{
			e.Print();
		}
	}
}

void Ex4()
{
	vector <Students> students_v
	{
		{1, "Kim", 80},
		{ 2, "Lee",20 },
		{ 3, "Park", 100 },
		{ 4, "Choi",30 }
	};

	bool IsQuit{ false };

	while (!IsQuit)
	{
		cout << "1. 학생 추가" << endl;
		cout << "2. 학생 제거(번호)" << endl;
		cout << "3. 전체 학생 추가" << endl;
		cout << "4. 총점 및 평균" << endl;
		cout << "5. 평균 이상의 목록" << endl;
		cout << "6. 종료" << endl;
		cout << "> ";

		int Command{};

		cin >> Command;

		
		switch (Command)
		{
		case 1:
			AddStudnet(students_v);
			break;
		case 2:
			RemoveStudent(students_v);
			break;
		case 3:
			PrintStudnet(students_v);
			break;
		case 4:
			PrintAverage(students_v);
			break;
		case 5:
			PrintOverAverage(students_v);
			break;
		case 6:
			IsQuit = true;
			break;
		default:
			cerr << "잘못된 명령어입니다" << endl;
			break;
		}
	}
}
