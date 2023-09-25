#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> OptimizeCombination(string target, const vector<string>& stringlist) 
{
    unordered_map<string, vector<string>> m;
    m[""] = {};

    for (int i = 1; i <= target.size(); i++) 
    {
        for (const auto& word : stringlist)
        {
            if (word.size() > i) continue;
            if (target.substr(i - word.size(), word.size()) != word) continue;
            if (m.count(target.substr(0, i - word.size())) == 0) continue;

            if (m.count(target.substr(0, i)) == 0 || m[target.substr(0, i)].size() > 1 + m[target.substr(0, i - word.size())].size()) 
            {
                m[target.substr(0, i)] = m[target.substr(0, i - word.size())];
                m[target.substr(0, i)].push_back(word);
            }
        }
    }

    return m[target];
}

void Print(const vector<string>& r) 
{
    cout << "{ ";
    for (auto i = r.begin(); i != r.end(); i++) 
    {
        cout << *i;
        if (next(i) != r.end()) 
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int main() 
{
    Print(OptimizeCombination("hello", { "he", "h", "e", "llo", "hell" }));
    Print(OptimizeCombination("abcdef", { "ab", "abc", "cd", "def", "abcd" }));
    Print(OptimizeCombination("programmer", { "pro", "gram", "mer", "program", "er", "m" }));
    Print(OptimizeCombination("impossible", { "i", "p", "si", "ble" }));
}
