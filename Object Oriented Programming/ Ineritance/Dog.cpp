#include <iostream>
#include "Dog.h"

Dog::Dog() : mBreed{BREED::Pomeranian}
{
    std::cout << "[+] Dog" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[-] Dog" << std::endl;
}

Dog::BREED Dog::GetBreed() const
{
    return mBreed;
}

void Dog::SetBreed(BREED breed)
{
    mBreed = breed;
}

void Dog::bark()
{
    std::cout << "bark" << std::endl;
}
