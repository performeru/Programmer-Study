#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>

using namespace rapidjson;
using namespace std;

struct Status 
{
	int mLevel{};
	int mHP{};
	int mMP{};
};

struct Item 
{
	string mName{};
	int mGold{};
};

class Monster 
{
private:
	string mName;
	Status mStatus;
	vector<Item> mItems;

public:
	void SetName(const string& name) { mName = name; }
	void SetStatus(const Status& status) { mStatus = status; }
	void AddDropItem(const Item& item) { mItems.push_back(item); }

	string& GetName() { return mName; }
	Status& GetStatus() { return mStatus; }
	vector<Item>& GetDropItem() { return mItems; }
};

bool SaveToJson(const string& path, vector<Monster>& monsters) 
{
	StringBuffer sb; 
	PrettyWriter<StringBuffer> writer(sb);

	writer.StartObject();
	writer.Key("monsters");
		writer.StartArray();
		for (auto monster : monsters) 
    		{
			writer.StartObject();
			{
				writer.Key("name"); writer.String(monster.GetName().c_str());

				writer.Key("status");
					writer.StartObject();
					{
						auto status = monster.GetStatus();
						writer.Key("level"); writer.Int(status.mLevel);
						writer.Key("hp"); writer.Int(status.mHP);
						writer.Key("mp"); writer.Int(status.mMP);
					}
					writer.EndObject();

				writer.Key("items");
					writer.StartArray();
					{
						for (auto item : monster.GetDropItem()) 
            					{
							writer.StartObject();
							writer.Key("name"); writer.String(item.mName.c_str());
							writer.Key("gold"); writer.Int(item.mGold);
							writer.EndObject();
						}
					}
					writer.EndArray();
			}
			writer.EndObject();
		}
		writer.EndArray();
	writer.EndObject();
	
	ofstream ofs;
	ofs.exceptions(ofstream::badbit | ofstream::failbit);

	try 
  	{
		ofs.open(path);
		ofs << sb.GetString();
		ofs.close();
	} 
  	catch (ofstream::failure& e) 
  	{
		cerr << "invalid operatiron in SaveToJson()" << endl;
		cerr << e.what() << endl;
		ofs.close();
		return false;
	}

	return true;
}

bool LoadFromJson(const string& path, vector<Monster>& monsters)
{
	ifstream ifs;
	ifs.exceptions(ifstream::badbit | ifstream::failbit);

	stringstream ss;

	try 
  	{
		ifs.open(path);

		ss << ifs.rdbuf();

		ifs.close();
	} 
  	catch (ifstream::failure& e) 
  	{
		cerr << "invalid operation in LoadFromJson()" << endl;
		cerr << e.what() << endl;
		ifs.close();
    
		return false;
	}

	Document doc;
	doc.Parse(ss.str().c_str());

	for (auto& monObject : doc["monsters"].GetArray())
 	{
		Monster monster;
		monster.SetName(monObject["name"].GetString());

		Status status;
		status.mLevel = monObject["status"].GetObject()["level"].GetInt();
		status.mHP = monObject["status"].GetObject()["hp"].GetInt();
		status.mMP = monObject["status"].GetObject()["mp"].GetInt();
		monster.SetStatus(status);

		for (auto& itemObject : monObject["items"].GetArray()) 
    		{
			Item item;
			item.mName = itemObject["name"].GetString();
			item.mGold = itemObject["gold"].GetInt();
			monster.AddDropItem(item);
		}

		monsters.push_back(monster);
	}

	return true;
}

int main() 
{
	vector<Monster> monsters;

	Monster m;
	m.SetName("슬라임");
	m.SetStatus({ 1,1,1 });
	m.AddDropItem({ "끈적한 젤리", 1 });
	monsters.push_back(m);

	m.GetDropItem().clear();
	m.SetName("늑대인간");
	m.SetStatus({ 5,5,5 });
	m.AddDropItem({ "발톱", 2 });
	m.AddDropItem({ "늑대가죽", 5 });
	monsters.push_back(m);

	m.GetDropItem().clear();
	m.SetName("악마");
	m.SetStatus({ 10,10,10 });
	m.AddDropItem({ "날개", 10 });
	m.AddDropItem({ "손톱", 5 });
	monsters.push_back(m);

	SaveToJson("Data/monsters.json", monsters);
	monsters.clear();
	LoadFromJson("Data/monsters.json", monsters);

	for (auto& monster : monsters) 
  	{
		cout << "Monster Name: " << monster.GetName() << endl
			<< "Status - Level: " << monster.GetStatus().mLevel
			<< ", HP: " << monster.GetStatus().mHP
			<< ", MP: " << monster.GetStatus().mMP << endl
			<< "Drop Items:" << endl;

		for (auto& item : monster.GetDropItem()) 
    		{
			cout << "  Item Name: " << item.mName
				<< ", Gold: " << item.mGold << endl;
		}
		cout << endl;
	}
}
