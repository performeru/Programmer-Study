#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	enum BREED
	{
		WelshCorgi,
		Poodle,
		Pomeranian
	};
private:
	BREED mBreed;

public:
	Dog();
	~Dog();

	Dog::BREED GetBreed() const;
	void SetBreed(BREED breed);

	void bark();

};
