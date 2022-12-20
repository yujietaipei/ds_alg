#ifndef SORTING_HPP
#define SORTING_HPP
//bubble sort
void bubble_sort(int* arr, int size);

//insertion sort
void insertion_sort(int* arr,int size);

//selection sort
int find_min_index(int* arr,int l,int r);
void selection_sort(int* arr, int size);

//quick sort
int partition(int* arr, int front, int end);
void quick_sort(int* arr, int front, int end);

//merge sort
void Merge(int* arr, int front, int mid, int end);
void merge_sort(int* arr, int front, int end);

// heap sort
void heapify(int* arr, int length, int root);
void heap_sort(int* arr, int length);
#endif