#include <iostream>

class String
{
private:
    char* mData;

public:
    String(const char* str)
    {
        int length{};
        while (str[length] != '\0')
        {
            length++;
        }

        mData = new char[length + 1];

        for (int i = 0; i <= length; i++)
        {
            mData[i] = str[i];
        }
    }

    ~String()
    {
        delete[] mData;
    }

    void Print() const
    {
        std::cout << mData << std::endl;
    }
};

int main()
{
    String s1{ "Hello World" };

    s1.Print();
}
