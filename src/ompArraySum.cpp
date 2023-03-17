#include <iostream>
#include <fstream>
#include <cstdlib>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[])
{
    double start = omp_get_wtime();

    const char* inputFile = argv[1];
    const int numThreads = atoi(argv[2]);
    int totalSum = 0;

    ifstream in(inputFile);

    int n;
    in >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        in >> array[i];
    }

    #pragma omp parallel num_threads(numThreads) reduction(+:totalSum)
    {
        int myId = omp_get_thread_num();
        int myFirst = myId * (n / numThreads);
        int myLast = (myId == numThreads-1) ? (n-1) : (myFirst + (n / numThreads) - 1);
        int mySum = 0;

        for (int i = myFirst; i <= myLast; i++)
        {
            mySum += array[i];
        }

        totalSum += mySum;
    }

    delete[] array;
    in.close();

    cout << endl << "Sum is " << totalSum << endl << endl;
    double end = omp_get_wtime();
    cout << "runtime = " << (end - start) << " sec" << endl;
    return 0;
}