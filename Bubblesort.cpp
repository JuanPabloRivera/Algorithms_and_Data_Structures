#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        static void bubblesort(vector<int> &arr){
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
    private:
        static void swap(vector<int> &arr, int a, int b){
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
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
    Solution::bubblesort(arr);
    printVector(arr);

    return 0;
}