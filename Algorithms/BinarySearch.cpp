#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int Solution::binarySearchRecursive(const vector<int> &arr, int val){
    return binarySearchRecursive(arr, val, 0, arr.size() - 1);
}

int Solution::binarySearchRecursive(const vector<int> &arr, int val, int left, int right){
    if (right >= left){
        int mid = (right + left) / 2;
        if (val == arr[mid]) return mid;
        else if (val < arr[mid]) return binarySearchRecursive(arr, val, left, mid - 1);
        else return binarySearchRecursive(arr, val, mid + 1, right);
    }else return -1;
}

int Solution::binarySearchIterative(const vector<int> &arr, int val){
    int left = 0;
    int right = arr.size() - 1;
    while (right >= left){
        int mid = (left + right) / 2;
        if (val == arr[mid]) return mid;
        else if (val < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> vec {1,2,2,3,4,5,8,15,20,22,29,31,40,45,50};
    
    int x{};
    cin >> x;

    int indexRec = Solution::binarySearchRecursive(vec, x);
    int indexIt = Solution::binarySearchIterative(vec, x);
    cout << "Recursive approach: " << indexRec << "\nIterarive approach: " << indexIt << endl;

    return 0;
}