#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;
// BRUTE FORCE
// TC : O(2^n)
// SC : O(n)

int64_t Fibonacci(int n)
{
	if (n <= 2)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// TC : O(n)
// SC : O(n)
int64_t Fibonacci_memo(int n, map<int, int64_t>& memo)
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


// Brute Force
// TC : O(2 ^ (m+n))
// SC : O(m+n)
int FindWay(int m, int n)
{
	if (m == 1 && n == 1) 
  { 
    return 1;
  }
	if (!m || !n) 
  { 
    return 0; 
  }

	return FindWay(m - 1, n) + FindWay(m, n - 1);
}

// TC : O(n) / O(m * n)
// SC : O(m+n)
int FindWay(int m, int n, map<string,int>& memo)
{
	string key = to_string(m) + "," + to_string(n);

	if (memo.count(key) == 1)
	{
		return memo[key];
	}

	string rkey = to_string(n) + "," + to_string(m);

	if (memo.count(rkey) == 1)
	{
		return memo[rkey];
	}

	if (m == 1 && n == 1) 
  	{ 
    	    return 1; 
  	}
	if (!m || !n) 
  	{
    	    return 0; 
  	}

	memo[key] = FindWay(m - 1, n, memo) + FindWay(m, n - 1, memo);
	return memo[key];
}
