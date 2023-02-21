#include <algorithm>
#include <iostream>
#include <vector>
#include <list> 
#include <cmath>
using namespace std;
 
// Function to sort arr[] of
// size n using bucket sort
vector<int> bucketSort()
{
    vector<int> items{1,64,420,900,5,5};


    //first we need to determine the max value, to know the amount of loops.
    int maxVal = items[0];
    for (int i = 1; i < items.size(); i++) {
        if (items[i] > maxVal) {
            maxVal = items[i];} }
    
    //the amount of digits can be determined with the func int( log10(number)+1)
    int n_digits = (int)(log10 (maxVal)+1); 
    //now we loop through every digit
    for (int z = 0; z < n_digits; z++){
        //buckets in matrix form which saves values on sorted indexes
        vector<vector<int>> matrix(10, vector<int>(0));
        //distribution
        for (int i = 0; i < items.size(); i++) {
            int value_index = (items[i] / (int)pow(10, z)) % 10;
            matrix[value_index].push_back(items[i]);}

        //gathering
        int gath_index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                items[gath_index++] = matrix[i][j];
            }
        }
    }

    
    return items;
}

int main()
{
    cout <<"working....\n";
    vector<int> a = bucketSort(); 
    cout << "Sorted array is \n";
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    return 0;
}