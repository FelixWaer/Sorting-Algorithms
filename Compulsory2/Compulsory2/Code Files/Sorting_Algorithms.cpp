#include <iostream>
#include <vector>

#include "Sorting_Algorithms.h"

/**
 * \brief Prints all the elements in the array
 * \param array The array you want to print
 * \param arraySize The number of elements in the array
 */
void print_Array(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * \brief Prints all the elements in the vector
 * \param vector The vector you want to print
 */
void print_Vector(std::vector<int>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * \brief Swaps two elements value
 * \param elementA One of the elements you want to switch
 * \param elementB The other element you want to switch
 */
void swap_Elements(int& elementA, int& elementB)
{
	int tempNumber = elementA;
	elementA = elementB;
	elementB = tempNumber;
}

/**
 * \brief Partitions the array in the quick sort function to sort it
 * \param array The array that is going to be sorted
 * \param start The index of the starting element
 * \param end The index of the last element
 * \return Returns the index of the pivot element
 */
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

/**
 * \brief Partitions the vector in the quick sort function to sort it
 * \param vector The Vector that is going to be sorted
 * \param start The index of the starting element
 * \param end The index of the last element
 * \return Returns the index of the pivot element
 */
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

/**
 * \brief Quick sorting algorithm that sorts a array
 * \param array The array that is going to be sorted
 * \param start The index of the starting element
 * \param end The index of the last element
 */
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

/**
 * \brief Quick sorting algorithm that sorts a vector
 * \param vector The vector that is going to be sorted
 * \param start The index of the starting element
 * \param end The index of the last element
 */
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

/**
 * \brief Merges the arrays that are getting split in the merge sort algorithm
 * \param vector The vector that is going to be sorted
 * \param start The index of the starting element
 * \param mid The middle number of amount of elements
 * \param end The index of the last element
 */
void merge_Arrays(std::vector<int>& vector, int start, int mid, int end)
{
	int arrayOneSize = mid - start + 1;
	int arrayTwoSize = end - mid;

	int* tempArrayOne = new int[arrayOneSize];
	int* tempArrayTwo = new int[arrayTwoSize];

	for (int i = 0; i < arrayOneSize; i++)
	{
		tempArrayOne[i] = vector[start + i];
	}
	for (int j = 0; j < arrayTwoSize; j++)
	{
		tempArrayTwo[j] = vector[j + mid + 1];
	}

	int indexVector = start;
	int indexArrayOne = 0;
	int indexArrayTwo = 0;

	while (indexArrayOne < arrayOneSize && indexArrayTwo < arrayTwoSize)
	{
		if (tempArrayOne[indexArrayOne] <= tempArrayTwo[indexArrayTwo])
		{
			vector[indexVector] = tempArrayOne[indexArrayOne];
			indexArrayOne++;
		}
		else
		{
			vector[indexVector] = tempArrayTwo[indexArrayTwo];
			indexArrayTwo++;
		}
		indexVector++;
	}

	while (indexArrayOne < arrayOneSize)
	{
		vector[indexVector] = tempArrayOne[indexArrayOne];
		indexArrayOne++;
		indexVector++;
	}
	while (indexArrayTwo < arrayTwoSize)
	{
		vector[indexVector] = tempArrayTwo[indexArrayTwo];
		indexArrayTwo++;
		indexVector++;
	}

	delete[] tempArrayOne;
	delete[] tempArrayTwo;
}

/**
 * \brief Merge sorting algorithm that sorts a vector 
 * \param vector The vector that is going to be sorted
 * \param start The index of the starting element
 * \param end The index of the last element
 */
void mergeSorting(std::vector<int>& vector, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int mid = start + (end - start) / 2;

	mergeSorting(vector, start, mid);
	mergeSorting(vector, mid + 1, end);

	merge_Arrays(vector, start, mid, end);
}

/**
 * \brief cocktail sorting algorithm that sorts a vector 
 * \param vector The vector that is going to be sorted
 */
void cocktailSorting(std::vector<int>& vector)
{
	int start = 0;
	int end = vector.size() - 1;
	bool swapped = true;

	while (swapped == true)
	{
		swapped = false;

		for (int i = 0; i < end; i++)
		{
			if (vector[i] > vector[i + 1])
			{
				swap_Elements(vector[i], vector[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
		{
			break;
		}

		swapped = false;
		end--;

		for (int i = end; i >= start; i--)
		{
			if (vector[i] > vector[i + 1])
			{
				swap_Elements(vector[i], vector[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}