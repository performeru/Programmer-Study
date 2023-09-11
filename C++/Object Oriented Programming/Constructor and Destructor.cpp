#include <iostream>


class ClassA
{
public:
	ClassA()
	{
		std::cout << "[ClassA 생성]" << std::endl;
	}

	~ClassA()
	{
		std::cout << "[ClassA 소멸]" << std::endl;
	}

};

class ClassB
{
	ClassA mA;

public:
	ClassB()
	{
		std::cout << "[ClassB 생성]" << std::endl;
	}
	~ClassB()
	{
		std::cout << "[ClassB 소멸]" << std::endl;
	}
};


int main() 
{
	ClassB MyClass;
}
