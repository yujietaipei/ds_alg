#include <iostream>
#include <random>
#include "sorting.hpp"
using namespace std;

void print(int* arr, int length){
    for(int i = 0;i < length;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000);

    int arr[10];
    for(int i = 0;i < 10;i++){
        arr[i] = dist(gen);
    }

    cout << "the unordered array is : ";
    print(arr, 10);

    quick_sort(arr, 0, 9);
    cout << "the ordered array is : ";
    print(arr, 10);

    return 0;
}