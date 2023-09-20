#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

using namespace std;

using result = shared_ptr<vector<int>>;

ostream& operator<<(ostream& os, const vector<int>& v) 
{
    cout << "{ ";
    for (int i = 0; i < v.size(); i++) 
    {
        cout << v[i];
        if (i < v.size() - 1) 
        {
            cout << ",";
        }
    }
    cout << " }";
    return os;
}

result HowSum(const vector<int>& numbers, int sum, unordered_map<int, result>& memo) 
{
    if (memo.count(sum) == 1) 
    {
        return memo[sum];
    }

    if (sum == 0) 
    {
        return make_shared<vector<int>>();
    }
    if (sum < 0) 
    {
        return nullptr;
    }

    for (const auto e : numbers) 
    {
        auto r = HowSum(numbers, sum - e, memo);
        if (r != nullptr) 
        {
            r->push_back(e);
            memo[sum] = r;
            return memo[sum];
        }
    }

   
    memo[sum] = nullptr;
    return memo[sum];
}

int main() 
{
    vector<int> numbers1 = { 2, 3, 5 };
    int sum1 = 8;

    vector<int> numbers2 = { };
    int sum2 = 7;

    unordered_map<int, result> memo;

    result result1 = HowSum(numbers1, sum1, memo);
    result result2 = HowSum(numbers2, sum2, memo);

    cout << boolalpha;
    cout << *result1 << endl;
    if (result2 != nullptr) 
    {
        cout << *result2 << endl;
    }
    else
    {
        cout << "no result" << endl;
    }
}
