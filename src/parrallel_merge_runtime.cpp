#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void rmerge(vector<int>& arr, int l, int m, int r) {
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
    // Original array is udpated, this saves memory.
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

void rmergeSort(vector<int>& arr, int l, int r) {
    // splitting 
    if (l < r) {
        int m = l + (r - l) / 2;
        // Call mergesort agai (recursively) on left and right array, until only one element is left. (The original arr will be changed cause of &)
        // int threshold = 8;
        // if ((r - l + 1)/(sizeof(arr) / sizeof(arr[0])) < threshold) {
        //     // If the number of elements is below the threshold, sort sequentially
        //     sort(arr.begin() + l, arr.begin() + r + 1);
        // } else {
        thread t1(rmergeSort, ref(arr), l, m);
        thread t2(rmergeSort, ref(arr), m + 1, r);
        t1.join();
        t2.join();
        // Call merge function 
        rmerge(arr, l, m, r);
    }
}

// Functie om de gemiddelde runtime van de functie te meten
double measureAverageRuntime(int numRuns)
{
  double totalTime = 0.0;

  for (int i = 0; i < numRuns; i++) {
    // Start de timer
    auto start = chrono::high_resolution_clock::now();

    // Roep de functie aan die we willen meten
    int size = 1000;
    int maxDigits = 10;
    vector<int> arr(size);
    for (int i = 0; i < size; i++){
        arr[i] =  (rand() % maxDigits);
     }

    // vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    rmergeSort(arr,0,n-1);

    // Stop de timer en meet de tijdsduur
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Voeg de tijdsduur toe aan de totale tijd
    totalTime += duration.count();
  }

  // Bereken en retourneer de gemiddelde tijdsduur
  return totalTime / numRuns;
}


int main()
{
  int numRuns = 10000; // Pas het aantal uit te voeren runs aan indien nodig
  double avgRuntime = measureAverageRuntime(numRuns);
  cout << "Gemiddelde runtime over " << numRuns << " runs: " << avgRuntime << " seconden" << endl;

  return 0;
}
