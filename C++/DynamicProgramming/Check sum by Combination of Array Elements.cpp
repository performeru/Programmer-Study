#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> memo;

bool CanSum(int sum, const vector<int>& numbers) 
{
    if (memo.find(sum) != memo.end()) 
    {
        return memo[sum];
    }
    if (sum == 0)
    {
        return true;
    }
    if (sum < 0) 
    {
        return false;
    }

    for (int num : numbers) 
    {
        int remainder = sum - num;
        if (CanSum(remainder, numbers)) 
        {
            memo[sum] = true;
            return true;
        }
    }

    memo[sum] = false;
    return false;
}

int main() 
{
    vector<int> numbers1 = {2, 3, 5};
    int sum1 = 8;
    
    vector<int> numbers2 = {8,6};
    int sum2 = 7;

    cout << boolalpha;
    cout << CanSum(sum1, numbers1) << endl;        
    cout << CanSum(sum2, numbers2) << endl;
}
