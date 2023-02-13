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
    vector<int> items{1,6,4,9};
    vector<vector<int>> matrix(10, vector<int>(0));

    //first we need to determine the max value, to know the amount of loops.
    int maxVal = items[0];
    for (int i = 1; i < items.size(); i++) {
        if (items[i] > maxVal) {
            maxVal = items[i];} }
    
    //the amount of digits can be determined with the func int( log10(number)+1)
    int n_digits = (int)(log10 (maxVal)+1); 
    cout << n_digits << " ";
    //now we loop through every digit

    //distribution
    for (int i = 0; i < 4; i++) {
        int value = items[i]%10;
        matrix[value].push_back(value);}
    //gathering
    int gath_index = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            items[gath_index++] = matrix[i][j];}
        }
    
    return items;
}
 
/* Driver program to test above function */
int main()
{
    cout <<"working....";
    vector<int> a = bucketSort(); 
    cout << "Sorted array is \n";
    for (int i = 0; i < 4; i++)
        cout << a[i] << " ";
    return 0;
}
