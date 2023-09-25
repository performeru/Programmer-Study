#include <iostream>
#include <vector>

using namespace std;

bool CanSum(int sum, const vector<int>& numbers) 
{
	vector<bool> table(sum + 1, false);
	
	table[0] = true;

	for (int i = 0; i <= sum; i++) 
  {
		if (table[i] == true) 
    {
			for (auto e : numbers) 
      {
				if (i + e <= sum) 
        {
					table[i + e] = true;
				}
			}
		}
  }
	return table[sum];
}

int main() 
{
	cout << boolalpha;
	cout << CanSum(8, { 2, 3, 5 });
}
