#include <iostream>
#include <vector>
#include <chrono>

#include "FlexTimer.h"
#include "Sorting_Algorithms.h"

#define PRINT(X) std::cout << (X) << std::endl
#define CLEAR_CONSOLE std::cout << "\033c"

int main() {
	std::vector<int> sortingVector;
	Timer timer;

	int arraySizeChoice = 0;
	int sortingAlgorithmChoice = 0;
	while (true)
	{
		PRINT("How many elements do you want to sort?");
		std::cin >> std::ws;
		int peek = std::cin.peek();
		if (std::isdigit(peek))
		{
			srand(time(NULL));
			std::cin >> arraySizeChoice;
			for (int i = 0; i < arraySizeChoice; i++)
			{
				sortingVector.push_back(rand());
			}
			CLEAR_CONSOLE;
		}
		else
		{
			std::string word;
			std::cin >> word;
			CLEAR_CONSOLE;
			continue;
		}

		while (true)
		{
			PRINT("Press 1 for quick sort");
			PRINT("Press 2 for merge sort");
			PRINT("Press 3 for cocktail sort");
			std::cin >> std::ws;
			peek = std::cin.peek();
			if (std::isdigit(peek))
			{
				std::cin >> sortingAlgorithmChoice;
				timer.start_Timer();
				switch (sortingAlgorithmChoice)
				{
				case 1:
					{
					quickSorting(sortingVector, 0, sortingVector.size() - 1);
					break;
					}
				case 2:
					{
					mergeSorting(sortingVector, 0, sortingVector.size() - 1);
					break;
					}
				case 3:
					{
					cocktailSorting(sortingVector);
					break;
					}
				default:
					{
					continue;
					}
				}
				timer.stop_Timer();
				break;
			}
			else
			{
				std::string word;
				std::cin >> word;
				CLEAR_CONSOLE;
			}
		}
		CLEAR_CONSOLE;
		std::cout << "time in seconds: " << timer.TimeResult_InSeconds() << std::endl;
		std::cout << "time in milliseconds: " << timer.TimeResult_InMilliseconds() << std::endl;
		std::cout << "you sorted " << arraySizeChoice << " amount of random numbers";

		PRINT("do you want to continue sorting?");
		PRINT("yes/no");
		std::string answer;
		std::cin >> answer;
		if (answer != "yes")
		{
			break;
		}
		sortingVector.clear();
		CLEAR_CONSOLE;
	}

	return 1;
}