#include <iostream>

class Student
{
private:
	std::string Name;
	int Number;
	int Score;

public:
	Student(std::string name, int number, int score) : Name(name), Number(number), Score(score){}

	void SetName(std::string name)
	{
		Name = name;
	}
	void SetNumber(int number)
	{
		Number = number;
	}
	void SetScore(int score)
	{
		Score = score;
	}

	std::string GetName() const
	{
		return Name;
	}
	int GetNumber() const
	{
		return Number;
	}
	int GetScore() const 
	{
		return Score;
	}

	void PrintStudent()
	{
		std::cout << Name << ", " << Number << ", " << Score << std::endl;
	}


};

int main() 
{
	std::string name{}; 
	int number{}, score{};
	std::cout << "이름, 번호, 점수를 입력하세요" << std::endl;

	std::cin >> name >> number >> score;

	Student student(name, number, score);

	student.PrintStudent();
}
