#include <iostream>
#include <vector>
#include <math.h>

void radixSort(int arr[], int n) {
  // Determine the number of digits in the largest number
  int maxVal = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }
  int numDigits = 0;
  while (maxVal > 0) {
    maxVal /= 10;
    numDigits++;
  }

  // Sort the array by each digit
  for (int digit = 0; digit < numDigits; digit++) {
    std::vector<int> buckets[10];
    std::cout << "Sorted array is \n";

    // Distribution pass
    for (int i = 0; i < n; i++) {
      int digitVal = (arr[i] / (int)pow(10, digit)) % 10;
      buckets[digitVal].push_back(arr[i]);
    }

    // Gathering pass
    int index = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < buckets[i].size(); j++) {
        arr[index++] = buckets[i][j];
      }
    }
  }
}

int main() {
  int arr[] = {97, 3, 100, 7, 294, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  radixSort(arr, n);

  std::cout << "Sorted array is \n";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}