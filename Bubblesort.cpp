#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

void Solution::bubblesort(vector<int> &arr){
    bool sorted = false;
    while (!sorted){
        sorted = true;
        int prev = arr[0];
        for (size_t i{1}; i < arr.size(); i++){
            if (arr[i] < prev){
                swap(arr, i, i-1);
                sorted = false;
            }
            prev = arr[i];
        }
    }
}

int main(){

    vector<int> arr {4,7,9,6,3,2,15,1,20,8,9,4,6};
    Solution::printVector(arr);
    Solution::bubblesort(arr);
    Solution::printVector(arr);

    return 0;
}