#include <iostream>                                                   //Quick Sort
                                                                      // Time Complexity: O(n log n)
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

void QuickSort(int input[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = input[(left + right) / 2];

    do
    {
        while(input[i] < pivot)
        {
            i++;
        }
        while (input[j] > pivot)
        {
            j--;
        }
        if(i <= j)
        {
            Swap(input[i], input[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
    {
        QuickSort(input, left, j - 1);
    }
    if (i < right)
    {
        QuickSort(input, i + 1, right);
    }
}

int main()
{   
    const int ARRAY_Size{ 5 };
    int array[ARRAY_Size]{ 8, 7, 2, 3, 1 };

    QuickSort(array, 0, ARRAY_Size - 1);

    Print(array, ARRAY_Size);

    return 0;
}
