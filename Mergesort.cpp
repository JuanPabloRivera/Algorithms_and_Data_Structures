#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        static void mergesort(vector<int> &arr){
            vector<int> merged(arr.size());
            mergesort(arr, merged, 0, arr.size() - 1);
        }
    private:

        static void mergesort(vector<int> &arr, vector<int> &container, int left, int right){
            if (right > left){
                int half = (left + right) / 2;
                mergesort(arr, container, left, half);
                mergesort(arr, container, half + 1, right);
                mergeHalves(arr, container, left, right);
            }
        }

        static void mergeHalves(vector<int> &arr, vector<int> &merged, int leftStart, int rightEnd){
            int start = leftStart;
            int leftEnd = (leftStart + rightEnd) / 2;
            int rightStart = leftEnd + 1;
            int c{leftStart};

            while (leftStart <= leftEnd && rightStart <= rightEnd){
                if (arr[leftStart] <= arr[rightStart]) merged[c] = arr[leftStart++];    //Copying the smaller element into the final array 
                else merged[c] = arr[rightStart++];
                c++;
            }
            
            //Once one of the halves is already merged, we just copy the remainder of the other half
            if (leftStart > leftEnd){
                for (int i{rightStart}; i <= rightEnd; i++){
                    merged[c] = arr[i];
                    c++;
                }
            }
            else {
                for (int i{leftStart}; i <= leftEnd; i++){
                    merged[c] = arr[i];
                    c++;
                }
            }
            //Finally we place our sorted portion in our original array
            for (int i{start}; i <= rightEnd; i++) arr[i] = merged[i];
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
    Solution::mergesort(arr);
    printVector(arr);

    return 0;
}