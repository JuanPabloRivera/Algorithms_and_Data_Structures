#ifndef _SOLUTION_H_
#define _SOLUTION_H_
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        static void quicksort(vector<int> &arr);
        static void mergesort(vector<int> &arr);
        static void bubblesort(vector<int> &arr);
        static int binarySearchRecursive(const vector<int> &arr, int x);
        static int binarySearchIterative(const vector<int> &arr, int x);

        static void printVector(const vector<int> &arr){
            cout << "[ ";
            for (int val: arr)
                cout << val << " ";
            cout << "]\n";
        }
    private:
        //QUICKSORT
        static void quicksort(vector<int> &arr, int left, int right);
        static int partition(vector<int> &arr, int left, int right);
        //MERGESORT
        static void mergesort(vector<int> &arr, vector<int> &temp, int left, int right);
        static void mergeHalves(vector<int> &arr, vector<int> &temp, int left, int right);
        //BINARYSEARCH
        static int binarySearchRecursive(const vector<int> &arr, int val, int left, int right);
        //OTHER
        static void swap(vector<int> &arr, int a, int b){
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
};

#endif //_SOLUTION_H_