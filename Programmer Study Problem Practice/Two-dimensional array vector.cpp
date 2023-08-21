#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;

	cout << "m :";
	cin >> m;
	cout << "n :";
	cin >> n;

	vector<vector<int>> v(m, vector<int>(n, -1));

    cout << "{" << endl;
    for (int i = 0; i < m; ++i) 
    {
        cout << "  {";
        for (int j = 0; j < n; ++j) 
        {
            cout << " " << v[i][j];
            if (j < n - 1) 
            {
                cout << ",";
            }
        }
        cout << " }";
        if (i < m - 1) 
        {
            cout << ",";
        }
        cout << endl;
    }
    cout << "}" << endl;

    return 0;
}
