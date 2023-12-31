#include <iostream>                                                   //Selection Sort
                                                                      // Time Complexity: O(n^2)
                                                                      // Space Complexity : O(n)
void Print(int input[], int count)
{
    for (int i = 0; i < count; i++)
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

void SelectionSort(int input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            if (input[minIndex] > input[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Swap(input[i], input[minIndex]);
        }
    }
}

int main()
{
    const int ARRAY_Size{ 5 };
    int array[ARRAY_Size]{ 8,7,2,3,1 };

    SelectionSort(array, ARRAY_Size);
    Print(array, ARRAY_Size);

    return 0;
}
