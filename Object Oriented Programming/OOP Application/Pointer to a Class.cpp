#include <iostream>

class MyClass
{
public:
	int mMyMemberFunction(float x)
	{
		std::cout << "멤버함수 호출" << std::endl;
		return 0;
	}

	static float mMyStacticFunction(int x)
	{
		std::cout << "정적 함수 호출" << std::endl;
		return 0;
	}
};

using FPter = int (MyClass::*)(float);
using FPter2 = float(*)(int);

int main()
{
	MyClass c;

	FPter p = &MyClass::mMyMemberFunction;

	(c.*p)(1.1f);

	MyClass c1;

	FPter2 p2 = &MyClass::mMyStacticFunction;

	p2(3);
}
