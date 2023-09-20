#include <iostream>
#include <map>

int64_t Fibonacci_memo(int n, std::map<int, int64_t>& memo) 
{
	if (memo.count(n) == 1) 
  {
		return memo[n];
	}
	
	if (n <= 2)
  {
		return 1;
	}

	memo[n] = Fibonacci_memo(n - 1, memo) + Fibonacci_memo(n - 2, memo);
	return memo[n];
}

int main() 
{
	std::map<int, int64_t> memo;
	std::cout << Fibonacci_memo(50, memo);
}
