#include <iostream>
#include <vector>

using namespace std;

int64_t Fibonacci(const int n) 
{
	vector<int64_t> table(n + 1, 0);

	table[0] = 0;
	table[1] = 1;

	for (int i = 2; i <= n; i++) 
  {
		table[i] = table[i - 1] + table[i - 2];
	}
	
	return table[n];
}

int main() 
{
	cout << Fibonacci(50) << endl;
}
