#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main(int args,char** argv){
	int arr[100],n,size,rank,local=0,global=0,chunk_size;
	//random elements
	for(int i=0;i<100;i++){
		arr[i]=rand()%101;
	}
	//for(int i=0;i<100;i++){
	///	printf("%d ",arr[i]);
	//}
	
	MPI_Init(&args,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);//ranks of the process ,the root(sort of like parent process)is always rank 0
	MPI_Comm_size(MPI_COMM_WORLD,&size);//total number of mpi process,
	//printf("size->[%d] ",size);
	//chunck_size (make the array in small arrays with chunk size
	chunk_size=100/size; //divde number of elements as per the chunks
	int newArr[chunk_size];//make array for each of the process
	
	//distributes data in mpi programs
	//(1)array ko (2) chunk_size me divide karo ,datatype (3) MPI_INT<-ye input keliye tha
	//(4) newArr me dalo of size (5
	MPI_Scatter(arr,chunk_size,MPI_INT,newArr,chunk_size,MPI_INT,0,MPI_COMM_WORLD);
	
	for(int i=0;i<chunk_size;i++)
		local+=newArr[i];
	
	

	MPI_Reduce(&local,&global,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0){
		printf("the sum of the array elements is%d\n",global);
	}
	MPI_Finalize();
	return 0;
	
}
