#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


class Monster
{
private:
    string mName;
    int mLevel;
    int mHP;
    int mMP;

public:
    Monster() = default;
    Monster(string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp } {}

    friend ostream& operator << (ostream& os, const Monster& m)
    {
        os << m.mName << "," << m.mLevel << "," << m.mHP << "," << m.mMP;
        return os;
    }

    friend istream& operator >> (istream& is, Monster& m)
    {
        string line;

        try
        {
            getline(is, line, ',');
            m.mName = line;
            getline(is, line, ',');
            m.mLevel = stoi(line);
            getline(is, line, ',');
            m.mHP = stoi(line);
            getline(is, line);
            m.mMP = stoi(line);
        }
        catch (exception e)
        {
            cerr << "파일 구조가 올바르지 않습니다." << endl;
        }

        return is;
    }
};

bool LoadFile(const string& filename, vector<Monster>& monsters)
{
    ifstream ifs;
    ifs.exceptions(ifstream::badbit);

    try
    {
        ifs.open(filename);

        string line;

        getline(ifs, line); // 첫 줄 제거

        while (!ifs.eof())
        {
            Monster m;
            ifs >> m;
            monsters.push_back(m);
        }

        ifs.close();
    }
    catch (ifstream::failure e)
    {
        cerr << e.code() << " - " << e.what() << endl;
        ifs.close();
        return false;
    }

    return true;
}

bool SaveFile(string filename, const vector<Monster>& monsters)
{
    ofstream ofs;
    ofs.exceptions(ofstream::badbit);

    try
    {
        ofs.open(filename);

        ofs << "---MONSTER DATA---" << endl;
        for (const auto& e : monsters)
        {
            ofs << e << endl;
        }

        ofs.close();
    }
    catch (ofstream::failure e)
    {
        cerr << endl << e.code() << "_" << e.what() << endl;
        ofs.close();
        return false;
    }

    return true;
}

int main()
{
    vector<Monster> monsters;

    monsters.push_back(Monster("ORC", 15, 15, 15));

    if (SaveFile("C:\\Study\\lesson\\FileSystem\\Data\\Simple_copy.txt", monsters))
    {
        cout << "Copy File saved successfully." << endl;
    }
    else
    {
        cout << "Failed to save the copy file." << endl;
    }


    return 0;
}

