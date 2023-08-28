#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Monster
{
private:
	string mName;
	int mLevel;
	int mHP;
	int mMP;

public:
	Monster(string name, int level, int hp, int mp) : mName{name}, mLevel{level}, mHP{hp}, mMP{mp} {}

	friend ostream& operator << os  
	{
		os << 

	}
};

bool LoadFile(const string& filename, vector<Monster>& monsters)
{
	//file stream
	ifstream ifs;
	ifs.exceptions(ifstream::badbit);

	//file operation
	try
	{
		ifs.open(filename);
		char ch;

		while (ifs.get(ch))
		{
			cout << ch;
		}

		ifs.close();
	}
	catch(ifstream::failure e)
	{
		cerr << e.code() << " - " << e.what() << endl;
		ifs.close();
		return false;
	}

	return true;


}

int main()
{
	vector<Monster>monsters;

	LoadFile("C:/Study/lesson/FileSystem/Data/Simple.txt");
}
