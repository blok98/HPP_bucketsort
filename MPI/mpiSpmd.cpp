/* spmd.c
 * ... illustrates the single program multiple data
 *      (SPMD) pattern using basic MPI commands.
 *
 * Compile by: mpic++ -o spmd spmd.c
 * Usage: mpirun -np 4 ./spmd
 */

#include <iostream>
#include <mpi.h>

using std::cout, std::endl;

int main(int argc, char** argv) {
	int id = -1, numProcesses = -1, length = -1;
	char myHostName[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
	MPI_Get_processor_name (myHostName, &length);

	cout << "Greetings from process " << id << " of " << numProcesses << " on " << myHostName << endl;

	MPI_Finalize();
	return 0;
}


