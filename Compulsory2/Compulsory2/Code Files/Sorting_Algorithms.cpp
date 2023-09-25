#include <iostream>
#include <vector>

#include "Sorting_Algorithms.h"

void print_Array(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void print_Vector(std::vector<int>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

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

int partition_Array(std::vector<int>& vector, int start, int end)
{
	int const pivot = vector[end];
	int leftElementIndex = start;

	for (int i = start; i <= end; i++)
	{
		if (vector[i] < pivot)
		{
			swap_Elements(vector[i], vector[leftElementIndex]);
			leftElementIndex++;
		}
	}
	swap_Elements(vector[leftElementIndex], vector[end]);

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

void quickSorting(std::vector<int>& vector, int start, int end)
{
	if (start > end)
	{
		return;
	}

	int const partitionIndex = partition_Array(vector, start, end);
	quickSorting(vector, start, partitionIndex - 1);
	quickSorting(vector, partitionIndex + 1, end);
}