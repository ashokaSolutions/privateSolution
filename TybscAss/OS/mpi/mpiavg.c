#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main(int args,char* argv[]){
	int arr[4],rank,size,local=0,global;
	for(int i=0;i<4;i++)
		arr[i]=rand()%50;
	for(int i=0;i<4;i++)
		printf("%d ",arr[i]);
	
	MPI_Init(&args,&argv);
	int rank,size,local=0;
	int global;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int chunk=4/size;
	int newArr[chunk];
	MPI_Scatter(arr,chunk,MPI_INT,newArr,chunk,MPI_INT,0,MPI_COMM_WORLD);
	for(int i=0;i<chunk;i++)
		local+=arr[i];
	
	MPI_Reduce(&local,&global,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
		printf("avg:%.2f",global/4);
	MPI_Finalize();
	return 0;
}
