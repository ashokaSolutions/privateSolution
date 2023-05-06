#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
int main(int args,char** argv){
	int array[100] ,global_min=0,global_max=0,local=0,rank,size,chunk;
	for(int i=0;i<100;i++){
		array[i]=rand()%100;
	}
	int local_min=0,local_max=0;
	MPI_Init(&args,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	
	chunk=100/size;
	int newArr[chunk];
	MPI_Scatter(array,chunk,MPI_INT,newArr,chunk,MPI_INT,0,MPI_COMM_WORLD);
	global_min=newArr[0];
	global_max=newArr[0];
	for(int i=0;i<chunk;i++){
		if(newArr[i]>local_max){
			local_max=newArr[i];
		}
		if(newArr[i]<local_min){
			local_min=newArr[i];
		}
	}
	MPI_Reduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
	MPI_Reduce(&local_max,&global_max,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
	if(rank==0){
		printf("the min:%d\n",global_min);
		printf("the max:%d\n",global_max);
	}
	MPI_Finalize();
	return 0;
}
