#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> & arr, int left, int mid, int right){
    // define sizes for left and right subarrays
    int size1 = mid - left + 1; 
    int size2 = right - mid; 

    // dcelare left and right subvectors
    vector<int> leftArr(size1);
    vector<int> rightArr(size2);

    // copy data to temp arrays
    for(int i = 0; i < size1; i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < size2; j++){
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left...right]
    int i = 0, j = 0, k = left;

    // iterate through left and right subarrays
    // to determine which to store in output array
    while(i < size1 && j < size2){
        if(leftArr[i] <= rightArr[j]){ // if the left element is smaller
            arr[k] = leftArr[i]; // store the left element in arr
            i++; // increment left array index
        }else{ // the right element is smaller
            arr[k] = rightArr[j]; // store the right element in arr
            j++; // increment the right array index
        }
        k++; // increment output array index
    }

    // Copy any remaining elements of leftArr
    while(i < size1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // copy any remaining elements of rightArr
    while(j < size2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// mergesort function which recursively calls itself on
// the left and right halves of the input vectors, and merges
// them after they are sorted
void mergeSort(vector<int> & arr, int left, int right){
    // only if left is still less than right
    // when left == right, it is 
    if(left < right){
        int mid = left + (right - left) / 2; // get middle

        // recursively sort first and second halves of array
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printVector(const vector<int>& arr){
    for(int num: arr){
        cout << num << " ";
    }
    cout << endl;

}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original Array: ";
    printVector(arr);

    mergeSort(arr, 0, arr.size() - 1 );

    cout << "Sorted Array: ";
    printVector(arr);

    return 0;
}