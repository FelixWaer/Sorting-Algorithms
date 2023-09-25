#include <iostream>
#include <vector>
#include <chrono>

#include "FlexTimer.h"
#include "Sorting_Algorithms.h"

#define PRINT(X) std::cout << (X) << std::endl
#define CLEAR_CONSOLE std::cout << "\033c"

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
		PRINT("How many elements do you want to sort?");
		std::cin >> std::ws;
		int c = std::cin.peek();
		if (std::isdigit(c))
		{
			srand(time(NULL));
			std::cin >> arraySizeChoice;
			for (int i = 0; i < arraySizeChoice; i++)
			{
				vectorThatIsGonnaBeSorted.push_back(rand());
			}
			CLEAR_CONSOLE;
			break;
		}
		else
		{
			std::string word;
			std::cin >> word;
			if (c == 'e' || c == 'E')
			{
				break;
			}
		}
	}

	Timer timer;
	timer.start_Timer();
	quickSorting(vectorThatIsGonnaBeSorted, 0, vectorThatIsGonnaBeSorted.size() - 1);
	timer.stop_Timer();
	std::cout << "time in seconds: " << timer.TimeResult_InSeconds() << std::endl;
	std::cout << "time in milliseconds: " << timer.TimeResult_InMilliseconds() << std::endl;

	std::cout << "you sorted " << arraySizeChoice << " amount of random numbers";
	int a = 0;
	std::cin >> a;

	return 1;
}