#include <iostream>
using namespace std;

template <typename T, size_t N>

void BubbleSort(T(&arr)[N]) 
{
	for (size_t i = 0; i < N - 1; i++) 
	{
		for (size_t j = 0; j < N - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <typename T, size_t N>

void PrintArray(T(&arr)[N]) 
{
	for (size_t i = 0; i < N; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() 
{
	int array[]{ 1, 2, 3, 5, 4 };
	BubbleSort(array);
	PrintArray(array);

	cout << "------------------" << endl;

	float array2[]{ 2.5f,2.1f,3.0f,5.1f};
	BubbleSort(array2);
	PrintArray(array2);
}
