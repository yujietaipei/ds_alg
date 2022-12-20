#include <iostream>
#include "sorting.hpp"

//bubble sort
void bubble_sort(int* arr, int size){
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int j = size-1;j > 0;j--){
            for(int k = 0;k < j;k++){
                if(arr[k] > arr[k+1]){
                    std::swap(arr[k],arr[k+1]);
                    flag = 1;
                }
            }
        }
    }

}

//insertion sort
void insertion_sort(int* arr,int size){
    for(int i = 1;i < size;i++){
        int key = arr[i];
        int j = i - 1;
        while(j > -1 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}
//selection sort
int find_min_index(int* arr,int l,int r){
    int min = l;
    for(int i = l+1;i <= r;i++){
        if(arr[i] < arr[min]){
            min = i;
        }
    }
    return min;
}

void selection_sort(int* arr, int size){
    for(int i = 0;i < size;i++){
        int min_idx = find_min_index(arr,i,size-1);
        std::swap(arr[i],arr[min_idx]);
    }
}

//quick sort
int partition(int* arr, int front, int end){
    int pivot = arr[end];
    int i = front - 1;
    for(int j = front;j < end;j++){
        if(arr[j] < pivot){
            std::swap(arr[++i],arr[j]);
        }
    }
    std::swap(arr[++i],arr[end]);
    return i;
}

void quick_sort(int* arr, int front, int end){
    if(front < end){
        int pivot = partition(arr,front,end);
        quick_sort(arr,front,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}

//merge sort
void Merge(int* arr, int front, int mid, int end){
    int front1 = front;
    int end1 = mid;
    int front2 = mid+1;
    int end2 = end;
    int tmp[end-front+1];
    int k = 0;
    while(front1 <= end1 && front2 <= end2){
        tmp[k++] = arr[front1] < arr[front2] ? arr[front1++]: arr[front2++];
    }
    while(front1 <= end1){
        tmp[k++] = arr[front1++];
    }
    while(front2 <= end2){
        tmp[k++] = arr[front2++];
    }
    k = 0;
    for(int i = front;i <= end;i++){
        arr[i] = tmp[k++];
    }
}

void merge_sort(int* arr, int front, int end){
    if(front < end){
        int mid = front + (end - front)/2;
        merge_sort(arr,front,mid);
        merge_sort(arr,mid+1,end);
        Merge(arr,front,mid,end);
    }
}

// heap sort

void heapify(int* arr, int length, int root){
    int left = root*2+1;
    int right = root*2+2;
    int largest = root;
    if(left < length && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < length && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != root){
        std::swap(arr[root],arr[largest]);
        heapify(arr,length,largest);
    }
}

void heap_sort(int* arr, int length){
    for(int i = length/2;i > -1;i--){
        heapify(arr,length,i);
    }
    for(int i = length-1;i > -1;i--){
        std::swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}