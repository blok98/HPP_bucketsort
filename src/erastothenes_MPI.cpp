#include <iostream>
#include <climits>
#include <mpi.h>
#include <vector>
#include <cmath>

#include <chrono>

using namespace std;
using namespace chrono;

vector<bool>* zeef(int N, int rank, int size){
    cout << "zeef is executed by process: " << rank << endl;
    int chunk_size = (N + size - 1) / size; 
    int start_index = rank * chunk_size + 2;
    int end_index = min(start_index + chunk_size, N);

    vector<bool>* is_prime = new vector<bool>(end_index - start_index, true);

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
    cout << "zeef finished executing for process: " << rank << endl;
    return is_prime;
}

int main(int argc, char** argv){

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 100;

    auto start_time = high_resolution_clock::now();

    vector<bool>* local_is_prime = zeef(N, rank, size);

    // Combineer de deelresultaten met reduce (gather)
    vector<bool>* global_is_prime = new vector<bool>(N+1, true);
    MPI_Reduce(local_is_prime, global_is_prime, N+1, MPI_C_BOOL, MPI_LAND, 0, MPI_COMM_WORLD);


    // Alleen op het masterproces:
    if (rank == 0) {
        auto end_time = high_resolution_clock::now();
        auto time_diff = duration_cast<milliseconds>(end_time - start_time);
        cout << "Execution time: " << time_diff.count() << " seconds" << endl;

        for (int i = 0; i <= N; i++) {
            if ((*global_is_prime)[i]) {
                cout << i << " is prime." << endl;
            }
        }
    }

    delete local_is_prime;
    if (rank == 0) {
        delete global_is_prime;
    }

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize();

    return 0;}