#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int mid = low + ((high - low) / 2); // get middle of the array
    // calculate the range between the high and low, and then add low
    // to shift to account for low index
    int pivot = arr[mid]; // set pivot to middle element
    cout << "mid: " << mid << endl;
    cout << "pivot: " << pivot << endl;
    
    // swap pivot to end of array
    swap(arr[mid], arr[high]);

    int i = low - 1; // index denoting the boundary for the left of pivot

    // iterate from low to high-1, excluding the pivot 
    for(int j = low; j <= (high - 1); j++){
        if(arr[j] < pivot){ // if the current array element 
                            // is less than or equal to the pivot
            i++; // increment the left boundary of the pivot to 
                 // include value at j
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // place the pivot in the proper position
                    // swapping it with the left-most element greater than it
    return i + 1; // return the partition index (pivot position)
}

// print for debugging
void printArray(vector<int> & arr){
    for(int num: arr){
        cout << num << " ";
    }
    cout << endl;
}

void quickSort(vector<int>& arr, int low, int high){
    // only perform quicksort if low is still less than high
    if(low < high){
        int pi = partition(arr, low, high); // get the initial pivot
                                        // and reordre elements to 
                                        // have less than on the left
                                        // and greatar than on the right

        // recursively call quicksort on left and right halves at pivot
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    cout << "Original Array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size()-1);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}