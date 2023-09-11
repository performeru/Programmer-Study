#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	enum BREED
	{
		KOREANSHORT,
		MUNCHKIN,
		RUSSIANBLUE,
		TURKISHANGORA
	};
private:
	BREED mBreed;

public:
	Cat();
	~Cat();

	Cat::BREED GetBreed() const;
	void SetBreed(BREED breed);

	void Grooming();
};
