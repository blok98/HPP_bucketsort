#include <algorithm>
#include <iostream>
#include <vector>
#include <list> 
#include <cmath>
using namespace std;
 
#include <chrono>
using namespace std::chrono;

// Function to sort arr[] of
// size n using bucket sort
vector<int> rbucketSort()
{
    int size = 10;
    int maxDigits = 10;
    vector<int> items(size);
    for (int i = 0; i < size; i++){
        items[i] =  (rand() % maxDigits);
     }

    // vector<int> items{166,64,1,69};

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

// Functie om de gemiddelde runtime van de functie te meten
double measureAverageRuntime(int numRuns)
{
  double totalTime = 0.0;

  for (int i = 0; i < numRuns; i++) {
    // Start de timer
    auto start = chrono::high_resolution_clock::now();

    // Roep de functie aan die we willen meten
    rbucketSort();

    // Stop de timer en meet de tijdsduur
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Voeg de tijdsduur toe aan de totale tijd
    totalTime += duration.count();
  }

  // Bereken en retourneer de gemiddelde tijdsduur
  return totalTime / numRuns;
}


int rmain()
{
  int numRuns = 10; // Pas het aantal uit te voeren runs aan indien nodig
  double avgRuntime = measureAverageRuntime(numRuns);

  cout << "Gemiddelde runtime over " << numRuns << " runs: " << avgRuntime << " seconden" << endl;

  return 0;
}

