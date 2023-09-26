#pragma once

void print_Array(int array[], int arraySize);
void print_Vector(std::vector<int>& vector);
void swap_Elements(int& elementA, int& elementB);

void quickSorting(int array[], int start, int end);
void quickSorting(std::vector<int>& vector, int start, int end);
void mergeSorting(std::vector<int>& vector, int start, int end);
void cocktailSorting(std::vector<int>& vector);
