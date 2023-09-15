#include <iostream>

#define PRINT(X) std::cout << (X) << std::endl

void swap_Elements(int& elementA, int& elementB)
{
	int tempNumber = elementA;
	elementA = elementB;
	elementB = tempNumber;
}

int partition_Array(int array[], int start, int end)
{
	int const pivot = array[end];
	int leftElementIndex = start;

	for (int i = start; i <= end; i++)
	{
		if (array[i] < pivot)
		{
			swap_Elements(array[i], array[leftElementIndex]);
			leftElementIndex++;
		}
	}
	swap_Elements(array[leftElementIndex], array[end]);

	return leftElementIndex;
}

void quickSorting(int array[], int start, int end)
{
	if (start > end)
	{
		return;
	}

	int const partitionIndex = partition_Array(array, start, end);
	quickSorting(array, start, partitionIndex - 1);
	quickSorting(array, partitionIndex + 1, end);
}

int main() {
	int constexpr  size = 12;
	int array[size] = {2, 5, 1, 5, 8, 7, 6, 6, 3, 10, 3, 6};

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	PRINT(" ");

	quickSorting(array, 0, size-1);

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	PRINT(" ");

	return 1;
}