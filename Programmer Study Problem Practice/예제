#include <iostream>

class Character
{
protected:
	int mHP{};

public:
	Character() : mHP(10) {};
	virtual ~Character() {};

public:
	virtual void Attack() const = 0;
	virtual void Dead() const = 0;
};

class Warrior : public Character
{
public:
	Warrior() 
	{
		std::cout << "[+] Warrior Created" << std::endl;
	};
	~Warrior() 
	{
		std::cout << "[-] Warrior Destroyed" << std::endl;
	};

public:
	void Attack() const override 
	{
		std::cout << "전사는 검을 휘둘렀다" << std::endl;
	}

	void Dead() const override
	{
		std::cout << "전사가 사망했다" << std::endl;
	} 

	void Attack() const override 
	{
		std::cout << "전사는 칼을 휘둘렀다" << std::endl;
	};

	void DoubleSlash() const
	{
		std::cout << "전사는 두 번 휘둘렀다" << std::endl;
	}
};

class Wolf : public Character
{
public:
	void Attack() const override
	{
		
	}

	void Dead() const override
	{
	
	}
};


int main()
{
	Character* p = new Warrior;
	p->Attack();
	p->Dead();
		
}
