#include <iostream>
#include <string>
#include <vector>
#include "tinyxml2.h"

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

class Monster2 
{
private:
	string mName{};
	Status mStatus{};
	vector<Item> mDropItems{};
public:
	void SetName(string name) { mName = name; }
	void SetStatus(const Status& status) { mStatus = status; }
	void AddDropItem(const Item& item) { mDropItems.push_back(item); }

	string GetName() const { return mName; }
	Status& GetStatus() { return mStatus; }
	vector<Item>& GetDropItems() { return mDropItems; }
};

void SaveToXML(string path, vector<Monster2>& monsters) 
{
	using namespace tinyxml2; 
	XMLDocument doc;
	
	XMLDeclaration* dec1 = doc.NewDeclaration(R"(xml version="1.0 encoding="EUC-KR")");
	doc.LinkEndChild(dec1);

	XMLElement* root = doc.NewElement("monsters");
	doc.LinkEndChild(root);

	for (auto& monster : monsters) 
    	{
		auto monElement = doc.NewElement("monster");
		monElement->SetAttribute("name", monster.GetName().c_str());
		
		auto statusElement = doc.NewElement("status");
		statusElement->SetAttribute("level", monster.GetStatus().mLevel);
		statusElement->SetAttribute("hp", monster.GetStatus().mHP);
		statusElement->SetAttribute("mp", monster.GetStatus().mMP);
		monElement->LinkEndChild(statusElement);

		auto itemsElement = doc.NewElement("items");
		for (auto& item : monster.GetDropItems()) 
        	{
			auto itemElement = doc.NewElement("item");
			itemElement->SetAttribute("name", item.mName.c_str());
			itemElement->SetAttribute("gold", item.mGold);
			itemsElement->LinkEndChild(itemElement);
		}
		monElement->LinkEndChild(itemsElement);

		root->LinkEndChild(monElement);
	}

	doc.SaveFile(path.c_str());
}

void LoadFromXML(string path, vector<Monster2>& monsters) 
{
	using namespace tinyxml2;
	XMLDocument doc;

	doc.LoadFile(path.c_str());

	auto root = doc.FirstChildElement("monsters");
    
	for (auto monElement = root->FirstChildElement("monster"); 
		monElement != nullptr;
		monElement = monElement->NextSiblingElement()) 
	{
		Monster2 monster;
		monster.SetName(monElement->Attribute("name"));

		auto statusElement = monElement->FirstChildElement("status");
		Status status;
		status.mLevel = statusElement->IntAttribute("level");
		status.mHP = statusElement->IntAttribute("hp");
		status.mMP = statusElement->IntAttribute("mp");
		monster.SetStatus(status);

		auto itemsElement = monElement->FirstChildElement("items");
        
		for (auto itemElement = itemsElement->FirstChildElement();
			itemElement;
			itemElement = itemElement->NextSiblingElement()) 
		{
			Item item;
			item.mName = itemElement->Attribute("name");
			item.mGold = itemElement->IntAttribute("gold");
			monster.AddDropItem(item);
		}

		monsters.push_back(monster);
	}
}

int main() 
{
	vector<Monster2> monsters;

	Monster2 m;
	m.SetName("슬라임");
	m.SetStatus({ 1,1,1 });
	m.AddDropItem({ "끈적한 젤리", 1 });
	monsters.push_back(m);

	m.GetDropItems().clear();
	m.SetName("늑대인간");
	m.SetStatus({ 5,5,5 });
	m.AddDropItem({ "발톱", 2 });
	m.AddDropItem({ "늑대가죽", 5 });
	monsters.push_back(m);

	m.GetDropItems().clear();
	m.SetName("악마");
	m.SetStatus({ 10,10,10 });
	m.AddDropItem({ "날개", 10 });
	m.AddDropItem({ "손톱", 5 });
	monsters.push_back(m);

	SaveToXML("Data/monsters.xml", monsters);
	monsters.clear();
	LoadFromXML("Data/monsters.xml", monsters);

	for (auto& monster : monsters) 
    	{
              cout << "Monster Name: " << monster.GetName() << endl
                  << "Status - Level: " << monster.GetStatus().mLevel
                  << ", HP: " << monster.GetStatus().mHP
                  << ", MP: " << monster.GetStatus().mMP << endl
                  << "Drop Items:" << endl;

		for (auto& item : monster.GetDropItems()) 
       		{
		    cout << "  Item Name: " << item.mName
                      << ", Gold: " << item.mGold << endl;
		}
		cout << endl;
	}
}
