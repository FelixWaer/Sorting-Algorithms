#include <iostream>
#include <vector>
#include <chrono>

#define PRINT(X) std::cout << (X) << std::endl
#define CLEAR_CONSOLE std::cout << "\033c"
#define TIME(x) x = std::chrono::high_resolution_clock::now()
#define PRINT_TIME_MS(text, start, end) std::cout << text << std::chrono::duration_cast<std::chrono::nanoseconds>((end) - (start)).count() << " ns" << std::endl

class Timer
{
public:
	Timer()
	{
	
	}

	~Timer()
	{
	
	}
private:
	
};

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

void print_Array(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << " ";
	}
	PRINT(" ");
}

void splitting_Array(int array[], int start, int mid, int end)
{
	int subArrayOneSize = mid - start + 1;
	int subArrayTwoSize = end - mid;

	int* subArrayOne = new int[subArrayOneSize];
	int* subArrayTwo = new int[subArrayTwoSize];

	for (int i = 0; i < subArrayOneSize; i++)
	{
		subArrayOne[i] = array[start + i];
	}
	for (int i = 0; i < subArrayTwoSize; i++)
	{
		subArrayTwo[i] = array[mid + 1 + i];
	}


	delete[] subArrayOne;
	delete[] subArrayTwo;

}
void mergeSort(int array[], int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int const mid = start + (end - start) / 2;

	mergeSort(array, start, mid);
	mergeSort(array, mid + 1, end);
	splitting_Array(array, start, mid, end);
}

int main() {
	std::vector<int> vectorThatIsGonnaBeSorted;

	int arraySizeChoice = 0;
	while (true)
	{
		std::cin >> std::ws;
		int c = std::cin.peek();
		if (std::isdigit(c))
		{
			std::cin >> arraySizeChoice;
			for (size_t i = 0; i < arraySizeChoice; i++)
			{
				
			}
			CLEAR_CONSOLE;
		}
		else
		{
			break;
		}
	}

	print_Array(theArray, arraySize);

	TIME(auto startTime);
	quickSorting(theArray, 0, arraySize-1);
	TIME(auto endTime);
	PRINT_TIME_MS("time to sort array: ", startTime, endTime);

	print_Array(theArray, arraySize);

	return 1;
}