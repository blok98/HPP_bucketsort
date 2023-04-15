#include <iostream>
#include <climits>
#include <mpi.h>
#include <vector>
#include <cmath>

using namespace std;

// loops over nonprimes and returns false if number is in the nonprimes
bool is_prime(int number, vector<int> non_primes){
    for (int i=0; i<non_primes.size(); i++){
        if (number==non_primes[i]){
            return false;
        }
    }
    return true;
}

vector<int> zeef(int N){
    vector<int> non_primes;
    vector<int> primes;
    int k=2;
    // first we loop over all elements until N
    for (int i = k; i<N; i++){
        // Than we loop until loop value is when k^2>n (j in our case)
        for (int j=k; pow(j,2)<N; j++){
            // all multiples of i{2..N} with factor of j{2..root(N)} are non primes
            non_primes.push_back(i*j);
        }
        // all values declared to i {2..N} are primes, if not in non_primes.
        if (is_prime(i, non_primes)){
            primes.push_back(i);
        }
    }
    return primes;
}

int main(){
    vector<int> a = zeef(100);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

}