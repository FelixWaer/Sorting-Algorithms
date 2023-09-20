#include <iostream>
#include <vector>

#define PRINT(X) std::cout << (X) << std::endl
#define CLEAR_CONSOLE std::cout << "\033c"

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

void print_Array(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << " ";
	}
	PRINT(" ");
}

int main() {
	int arraySize = 10;
	int theArray[10];

	int b = 0;
	while (true)
	{
		std::cin >> std::ws;
		int c = std::cin.peek();
		if (std::isdigit(c) || c=='-')
		{
			if (b == arraySize)
			{
				break;
			}
			std::cin >> theArray[b];
			b++;
			CLEAR_CONSOLE;
		}
		else
		{
			break;
		}
	}

	print_Array(theArray, arraySize);

	quickSorting(theArray, 0, arraySize-1);

	print_Array(theArray, arraySize);

	return 1;
}