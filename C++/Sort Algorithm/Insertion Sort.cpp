#include <iostream>                                                   //Insertion Sort
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

void InsertionSort(int input[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;
        int target = input[i];
        while(--j >= 0 && target < input[j])
        {
            input[j + 1] = input[j];
            input[j] = target;
        }
    }
}

int main()
{   
    const int ARRAY_Size{ 5 };
    int array[ARRAY_Size]{ 8, 7, 2, 3, 1 };

    InsertionSort(array, ARRAY_Size);
    Print(array, ARRAY_Size);

    return 0;
}
