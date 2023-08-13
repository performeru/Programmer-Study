#include <iostream>

class Student
{
private:
    std::string Name;
    int Number;
    int Score;

public:
    Student() : Name(""), Number(0), Score(0) {}

    Student(std::string name, int number, int score) : Name(name), Number(number), Score(score) {}

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

bool CompareStudents(const Student& score1, const Student& score2)
{
    return score1.GetScore() > score2.GetScore(); 
}

void SortStudentsByScore(Student* students, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (students[j].GetScore() < students[j + 1].GetScore())
            {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}

int main()
{
    int n{};
    std::cout << "학생 수를 입력하세요" << std::endl;
    std::cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++)
    {
        std::string name;
        int number, score;

        std::cout << "이름, 번호, 점수를 입력하세요 : ";
        std::cin >> name >> number >> score;

        students[i] = Student(name, number, score);
    }

    SortStudentsByScore(students, n);

    std::cout << "점수로 정렬된 학생 리스트:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        students[i].PrintStudent();
    }

    delete[] students;

}
