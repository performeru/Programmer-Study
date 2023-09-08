#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Header
{
	int version{ 1 };
	int itemCount{};
};

class Monster
{
private:
	std::string mName{};
	int mLevel{};
	int mHP{};
	int mMP{};

public:
	Monster() = default;
	Monster(std::string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp }
	{
	}

	void SetName(std::string name) { mName = name; }
	void SetLevel(int level) { mLevel = level; }
	void SetHP(int hp) { mHP = hp; }
	void SetMP(int mp) { mMP = mp; }

	void ReadText(std::istream& is)
	{
		std::string line;

		try
		{
			std::getline(is, line, ',');
			mName = line;
			std::getline(is, line, ',');
			mLevel = std::stoi(line);
			std::getline(is, line, ',');
			mHP = std::stoi(line);
			std::getline(is, line);
			mMP = std::stoi(line);
		}
		catch (std::exception e)
		{
			std::cerr << "파일 구조가 올바르지 않습니다." << std::endl;
		}
	}
	void WriteText(std::ostream& os)
	{
		os << mName << "," << mLevel << "," << mHP << "," << mMP << std::endl;
	}

	void WriteBinary(std::ostream& os)
	{
		int nameLen = static_cast<int>(mName.size());
		os.write(reinterpret_cast<char*>(&nameLen), sizeof(int));
		os.write(mName.c_str(), nameLen);
		os.write(reinterpret_cast<char*>(&mLevel), sizeof(int));
		os.write(reinterpret_cast<char*>(&mHP), sizeof(int));
		os.write(reinterpret_cast<char*>(&mMP), sizeof(int));
	}

	void ReadBinary(std::istream& is)
	{
		int nameLen{};
		is.read(reinterpret_cast<char*>(&nameLen), sizeof(int));
		//is.read(reinterpret_cast<char*>(&mName), nameLen);
		is.read(&mName[0], nameLen);
		is.read(reinterpret_cast<char*>(&mLevel), sizeof(int));
		is.read(reinterpret_cast<char*>(&mHP), sizeof(int));
		is.read(reinterpret_cast<char*>(&mMP), sizeof(int));
	}
};

bool LoadFile(const std::string& filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		ifs.open(filename);

		std::string line;

		std::getline(ifs, line);
		while (!ifs.eof())
		{
			Monster m;
			
			m.ReadText(ifs);

			monsters.push_back(m);
		}

		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ifs.close();
		return false;
	}
	
	return true;
}

bool SaveFile(std::string filename, std::vector<Monster>& monsters)
{
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit);

	try
	{
		ofs.open(filename);

		ofs << "--- MONSTER DATA ---" << std::endl;
		for (auto& e : monsters)
		{
			e.WriteText(ofs);
		}

		ofs.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ofs.close();
		return false;
	}

	return true;
}

bool SaveFileBinary(std::string filename, std::vector<Monster>& monsters)
{
	std::ofstream ostream;

	ostream.exceptions(std::ofstream::badbit);

	try
	{
		ostream.open(filename, std::ofstream::binary);

		Header header{ 1, static_cast<int>(monsters.size()) };
		ostream.write(reinterpret_cast<char*>(&header), sizeof(Header));
		for (auto& e : monsters)
		{
			e.WriteBinary(ostream);
		}
		ostream.close();
	}
	catch(std::ofstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ostream.close();
		return false;
	}

	return true;
}

bool LoadFileBinary(std::string filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		ifs.open(filename, std::ifstream::binary);

		Header header;
		ifs.read(reinterpret_cast<char*>(&header), sizeof(Header));
		for (int i = 0; i < header.itemCount; ++i)
		{
			Monster m;
			m.ReadBinary(ifs);
			monsters.push_back(m);
		}

		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ifs.close();
		return false;
	}

	return true;
}

int main()
{
	std::vector<Monster> monsters;

	LoadFile("Data/SimpleData.txt", monsters);

	monsters.push_back( Monster("ORC", 15, 15, 15) );

	SaveFile("Data/SimpleData_copy.txt", monsters);

	//////////////////////////////

	SaveFileBinary("Data/SimpleData.bin", monsters);
	std::vector<Monster> v;
	LoadFileBinary("Data/SimpleData.bin", v);
}
