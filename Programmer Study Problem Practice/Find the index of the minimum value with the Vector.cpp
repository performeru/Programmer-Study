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
    int MinIndex{};
    int MinValue = Vector[MinIndex];

    for (int i = 0; i < Vector.size(); i++) 
    {
        if (Vector[i] < MinValue) 
        {
            MinIndex = i;
            MinValue = Vector[i];
        }
    }

    for (int i = 0; i < Vector.size(); i++) 
    {
        cout << Vector[i] << " ";
    }

    cout << endl << "벡터에서 최솟값의 인덱스 : " << MinIndex << endl;
}
