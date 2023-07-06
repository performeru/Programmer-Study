#include <iostream>                                                   //Bubble Sort
                                                                      // Time Complexity: O(n^2)
                                                                      // Space Complexity : O(n)
void Print(int input[], int count)
{
    for(int i = 0; i < count; i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

void Swap(int& value, int& value2)
{
    int temp = value;
    value = value2;
    value2 = temp;
}

void BubbleSort(int input[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(input[j] > input[j + 1])
            {
                Swap(input[j], input[j + 1]);
            }
        }
    }
}

int main()
{   
    const int ARRAY_Size{ 5 };
    int array[ARRAY_Size]{ 8, 7, 2, 3, 1 };

    BubbleSort(array, ARRAY_Size);
    Print(array, ARRAY_Size);

    return 0;
}

