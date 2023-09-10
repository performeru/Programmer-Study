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
    Monster() : mName(), mLevel(), mHP(), mMP() {}
    Monster(string name, int level, int hp, int mp)
        : mName(name), mLevel(level), mHP(hp), mMP(mp) {}

    friend istream& operator>>(istream& is, Monster& m)
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
        catch (exception& e) 
        {
            cerr << "operator input error occurred." << endl;
        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const Monster& m) 
    {
        try 
        {
            os << m.mName << "," << m.mLevel << "," << m.mHP << "," << m.mMP;
        }
        catch (exception& e) 
        {
            cerr << "operator output error occurred." << endl;
        }

        return os;
    }
};

bool LoadFile(const char* filename, vector<Monster>& monsters) 
{
    ifstream ifs;
    ifs.exceptions(ifstream::badbit);

    try 
    {
        ifs.open(filename);

        string line;
        vector<std::string> data;

        getline(ifs, line); 

        while (!ifs.eof()) 
        {
            if (ifs.peek() == EOF) 
            {
                break;
            }

            Monster m;
            ifs >> m;
            monsters.push_back(m);
        }

        ifs.close();
    }
    catch (const std::ifstream::failure& e) 
    {
        cerr << endl << e.code() << " ... " << e.what() << endl;
        ifs.close();
        return false;
    }

    return true;
}

bool SaveFile(const char* filename, const vector<Monster>& monsters) 
{
    ofstream ofs;
    ofs.exceptions(ofstream::badbit);

    try 
    {
        ofs.open(filename);

        ofs << "--- MONSTER DATA ---" << endl;

        for (const auto& m : monsters) 
        {
            ofs << m << std::endl;
        }

        ofs.close();
    }
    catch (const ofstream::failure& e)
    {
        cerr << endl << e.code() << " ... " << e.what() << endl;
        ofs.close();
        return false;
    }

    return true;
}

int main() 
{
    vector<Monster> monsters;

    if (LoadFile("Monster.txt", monsters)) 
    {
        for (const auto& e : monsters) 
        {
            cout << e << endl;
        }
    }

    monsters.push_back(Monster("ORK", 15, 15, 15));

    if (SaveFile("Monster_copy.txt", monsters)) 
    {
        cout << "New monster added." << endl;
    }
}
