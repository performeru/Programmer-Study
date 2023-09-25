#include <iostream>
#include <vector>

using namespace std;

int FindWays(int m, int n) 
{
	vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

	table[1][1] = 1;

	for (int row = 0; row <= m; row++)
  {
		for (int col = 0; col <= n; col++)
    {
			if (row + 1 <= m)
      {
				table[row + 1][col] += table[row][col];
			}
			if (col + 1 <= n)
      {
				table[row][col + 1] += table[row][col];
			}
		}
	}

	return table[m][n];
}

int main() 
{
	cout << FindWays(3, 3) << endl;
}
