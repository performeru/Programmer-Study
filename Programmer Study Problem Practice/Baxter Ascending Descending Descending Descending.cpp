#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    int mNumber;
    int mScore;
    string mName;
};

bool compareByScore(const Student& a, const Student& b) 
{
    return a.mScore < b.mScore;
}

int main()
{
    vector<Student> number
    {
        {1, 100, "Doggy"},
        { 2, 50 ,"Kitty" },
        { 3, 90 , "Piggy" },
        { 4, 20, "Bunny" }
    };

    sort(number.begin(), number.end(), compareByScore);

    cout << "Ascending Order by Score" << endl;

    for (const Student& student : number) 
    {
        cout << student.mNumber << " , " << student.mScore << " , " << student.mName << endl;
    }

    cout << "____________________________" << endl;

    sort(number.begin(), number.end(), [](const Student& a, const Student& b) 
    {
        return a.mScore > b.mScore;
    });

    cout << "Descending Order by Score" << endl;

    for (const Student& student : number) 
    {
        cout << student.mNumber << " , " << student.mScore << " , " << student.mName << endl;
    }
}
