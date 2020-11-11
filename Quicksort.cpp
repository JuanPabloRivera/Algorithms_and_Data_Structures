#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;


void Solution::quicksort(vector<int> &arr){
    quicksort(arr, 0, arr.size()-1);     //Calling the actual quicksort method
}

void Solution::quicksort(vector<int> &arr, int left, int right){
    if (right > left){                              //if we haven´t finished sorting
        int index = partition(arr, left, right);    //We get the index of the position where the pivot must finish
        quicksort(arr, left, index - 1);            //we sort the left side of the pivot
        quicksort(arr, index + 1, right);           //we sort the right side of the pivot
    }
}

int Solution::partition(vector<int> &arr, int left, int right){
    int pivot = arr[right];           //we take the last element of the subarray as our pivot

    int i{left - 1};                  //points to the index where the last element <= pivot sits.

    for (int j{left}; j < right; j++){
        if (arr[j] <= pivot){         //if arr[j] is <= pivot then we add 1 to i, cause there's now one more element in the "<=" segment
            i++;
            swap(arr, i, j);          //we also swap the current element with the one in the position 
        }
    }
    swap(arr, i + 1, right);          //Cambiamos el pivote por el siguiente elemento más grande que el
    return i + 1;                     //Regresamos
}

int main(){

    vector<int> arr {4,7,9,6,3,2,15,1,20,8,9,4,6};
    Solution::printVector(arr);
    Solution::quicksort(arr);
    Solution::printVector(arr);

    return 0;
}