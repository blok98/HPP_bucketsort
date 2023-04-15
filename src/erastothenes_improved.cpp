#include <iostream>
#include <climits>
#include <mpi.h>
#include <vector>
#include <cmath>

#include <chrono>

using namespace std;
using namespace chrono;

vector<bool>* zeef(int N){
    vector<bool>* is_prime = new vector<bool>(N+1, true);
    int k=2;
    // first we loop over all elements until N
    for (int i = k; i<N; i++){
        // Than we loop until loop value is when k^2>n (j in our case)
        for (int j=k; pow(j,2)<N; j++){
            // all multiples of i{2..N} with factor of j{2..root(N)} are non primes
            (*is_prime)[i*j] = false;
        }
        // all values declared to i {2..N} are primes, if not already set to non_prime in above.
        // because default value of array is_prime is true, we dont need to declare it again.
    }
    cout << "checking...";
    // for (int i = 0; i<N; i++){
    //     int value=(*is_prime)[i];
    //     cout << value;
    // }
    return is_prime;
}

int main(){
    auto start_time = high_resolution_clock::now();
    // returns a list from 0 to N with boolean values stating if the index number is a prime or not.
    vector<bool>* a = zeef(100);
    // for (int i = 0; i < a->size(); i++) {
    //     cout << (*a)[i] << " ";
    // }
    delete a;
    auto end_time = high_resolution_clock::now();
    auto time_diff = duration_cast<milliseconds>(end_time - start_time);
    cout << "Execution time: " << time_diff.count() << " seconds" << endl;
    cout << endl;
}