#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int args,char* argv[]){
	int arr[100],localOdd=0,globalOdd=0,localEven=0,globalEven=0;
	for(int i=0;i<100;i++)
		arr[i]=rand()%100;
	for(int i=0;i<100;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	MPI_Init(&args,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	
	int chunk=100/size;
	int newArr[chunk];
	
	MPI_Scatter(arr,chunk,MPI_INT,newArr,chunk,MPI_INT,0,MPI_COMM_WORLD);
	
	for(int i=0;i<chunk;i++){
		if(arr[i]%2==0)
			localEven+=arr[i];
		else
			localOdd+=arr[i];
	}
	MPI_Reduce(&localOdd,&globalOdd,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	MPI_Reduce(&localEven,&globalEven,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	
	if(rank==0){
		printf("\nodd sum:%d\n",globalOdd);
		printf("\nodd sum:%d\n",globalEven);
	}
	
	MPI_Finalize();
	return 0;
}
