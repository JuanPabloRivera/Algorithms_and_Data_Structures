#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        static void quicksort(vector<int> &arr){
            quicksort(arr, 0, arr.size()-1);     //Calling the actual quicksort method
        }

    private:
        static void quicksort(vector<int> &arr, int left, int right){
            if (right > left){                              //if we haven´t finished sorting
                int index = partition(arr, left, right);    //We get the index of the position where the pivot must finish
                quicksort(arr, left, index - 1);            //we sort the left side of the pivot
                quicksort(arr, index + 1, right);           //we sort the right side of the pivot
            }
        }

        static void swap(vector<int> &arr, int a, int b){
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }

        static int partition(vector<int> &arr, int left, int right){
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
};

void printVector(const vector<int> &vec){
    cout << "[ ";
    for (int val: vec)
        cout << val << " ";
    cout << "]\n";
}

int main(){

    vector<int> arr {4,7,9,6,3,2,15,1,20,8,9,4,6};
    printVector(arr);
    Solution::quicksort(arr);
    printVector(arr);

    return 0;
}