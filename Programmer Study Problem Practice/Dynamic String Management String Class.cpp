#include <iostream>

class String
{
private:
    char* mData;

public:
    String() : mData(nullptr) {}

    String(size_t size)
    {
        mData = new char[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            mData[i] = ' ';
        }
        mData[size] = '\0';
    }

    String(const char* string)
    {
        size_t len = 0;
        while (string[len] != '\0')
        {
            len++;
        }
        mData = new char[len + 1];
        for (size_t i = 0; i <= len; i++)
        {
            mData[i] = string[i];
        }
    }

    String(const String& other)
    {
        size_t len = 0;
        while (other.mData[len] != '\0')
        {
            len++;
        }
        mData = new char[len + 1];
        for (size_t i = 0; i <= len; i++)
        {
            mData[i] = other.mData[i];
        }
    }

    ~String()
    {
        delete[] mData;
    }

    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] mData;
            size_t len = 0;
            while (other.mData[len] != '\0')
            {
                len++;
            }
            mData = new char[len + 1];
            for (size_t i = 0; i <= len; i++)
            {
                mData[i] = other.mData[i];
            }
        }
        return *this;
    }

    String operator+(const String& other) const
    {
        size_t len1 = 0;
        while (mData[len1] != '\0')
        {
            len1++;
        }
        size_t len2 = 0;
        while (other.mData[len2] != '\0')
        {
            len2++;
        }

        char* temp = new char[len1 + len2 + 1];

        for (size_t i = 0; i < len1; i++)
        {
            temp[i] = mData[i];
        }

        for (size_t i = 0; i <= len2; i++)
        {
            temp[len1 + i] = other.mData[i];
        }
        temp[len1 + len2] = '\0';
        String result(temp);
        delete[] temp;
        return result;
    }

    char& operator[](size_t index)
    {
        return mData[index];
    }

    const char& operator[](size_t index) const
    {
        return mData[index];
    }

    String& operator+=(const String& other)
    {
        size_t len1 = 0;
        while (mData[len1] != '\0')
        {
            len1++;
        }

        size_t len2 = 0;
        while (other.mData[len2] != '\0')
        {
            len2++;
        }

        char* temp = new char[len1 + len2 + 1];
        for (size_t i = 0; i < len1; i++)
        {
            temp[i] = mData[i];
        }
        for (size_t i = 0; i <= len2; i++)
        {
            temp[len1 + i] = other.mData[i];
        }
        temp[len1 + len2] = '\0';
        delete[] mData;
        mData = temp;
        return *this;
    }

    char* GetData() const
    {
        return mData;
    }
};

int main()
{
    std::cout << "빈 문자열 생성" << std::endl;
    String empty;

    std::cout << "크기를 지정하여 공백 문자열 생성" << std::endl;
    size_t size;
    std::cout << "크기를 입력하세요: ";
    std::cin >> size;
    String sized(size);

    std::cout << "문자열 리터럴로 생성" << std::endl;
    String s1("Hello");

    std::cout << "다른 스트링을 복사" << std::endl;
    String s2(s1);

    std::cout << "두 문자열을 이어붙임" << std::endl;
    String s3 = s1 + s2;

    std::cout << "배열 표기 사용" << std::endl;
    std::cout << "s3[0]: " << s3[0] << ", s3[1]: " << s3[1] << std::endl;

    std::cout << "대입 연산자" << std::endl;
    String s4;
    s4 += s3;

    std::cout << "8. 최종 결과 출력" << std::endl;
    std::cout << "s4: " << s4.GetData() << std::endl;

    return 0;
}
