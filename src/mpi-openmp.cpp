#include <iostream>
#include <mpi.h>
#include <omp.h>
#include <thread>

using std::cout, std::endl;

int main(int argc, char** argv) {
	int id = -1, numProcesses = -1, length = -1;
	char myHostName[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
	MPI_Get_processor_name (myHostName, &length);

    omp_set_num_threads(4);
#pragma omp parallel for
    for (size_t i = 0; i < 4; i++)
    {
		std::this_thread::sleep_for(std::chrono::milliseconds(id * 1000 + i*200));
		cout << "Greetings from thread " + std::to_string(omp_get_thread_num()) + " in process " + std::to_string(id) + " of " + std::to_string(numProcesses) + " on " + myHostName + "\n";
	}

    MPI_Finalize();
	return 0;
}

