#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    // Calculate the length of the two subarrays that need to be merged
    int n1 = m - l + 1; // length of the left subarray (or index of the middle)
    int n2 = r - m;     // length of the right subarray

    // Create two temp lists to store the elements of the subarrays
    vector<int> L(n1); // left subarray
    vector<int> R(n2); // right subarray

    // Splitting the array into L(left array) and R(right array)
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i]; // Copy elements from the left part of the array
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; // Copy elements from the right part of the array
    }

    // Merge the two subarrays into the original array
    int i = 0; // Index of the left subarray
    int j = 0; // Index of the right subarray
    int k = l; // Index of the merged array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // If the element in the left subarray is smaller, put it in the merged array
            i++;
        } else {
            arr[k] = R[j]; // If the element in the right subarray is smaller, put it in the merged array
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subarray into the merged array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subarray into the merged array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    // splitting 
    if (l < r) {
        int m = l + (r - l) / 2;
        // Call mergesort again (recursively) on left and right array, until only one element is left. (The original arr will be changed cause of &)
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Call merge function 
        merge(arr, l, m, r);
    }
}

int main() {
    // Arr declaration. Arr is called with reference (&) in the functions above
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    cout << "Given array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, n - 1);
    cout << "\nSorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}