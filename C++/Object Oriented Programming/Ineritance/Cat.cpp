#include <iostream>
#include "Cat.h"

Cat::Cat() : mBreed{BREED::KOREANSHORT}
{
    std::cout << "[+] Cat" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[-] Cat" << std::endl;
}

Cat::BREED Cat::GetBreed() const
{
    return mBreed;
}

void Cat::SetBreed(BREED breed)
{
    mBreed = breed;
}

void Cat::Grooming()
{
    std::cout << "Grooming..." << std::endl;
}
