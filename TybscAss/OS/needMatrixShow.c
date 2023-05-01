#include<stdio.h>
int n=3,m=3 ,alloc[10][10],max[10][10],need[10][10],available[10];

void getAlloc(){
	for (int i=0;i<n;i++)    
    {    
        for (int j=0;j<m;j++)    
        {    
        
            printf("Enter a[%d][%d]: ",i,j);                
            scanf("%d",&alloc[i][j]);    
        }    
    
    }    
}
void getMax(){
	for (int i=0;i<n;i++)    
    {    
        for (int j=0;j<m;j++)    
        {    
        
            printf("Enter a[%d][%d]: ",i,j);                
            scanf("%d",&max[i][j]);    
        }    
    }    
}
void getNeed(){
	for (int i=0;i<n;i++)    
    {    
        for (int j=0;j<m;j++)    
        {    
        	need[i][j]=max[i][j]-alloc[i][j];    
        }    
        
    }    
}
void getAvailable(){
	for (int i=0;i<n;i++)    
    {    
    	 printf("Enter a[%d]:",i); 
         scanf("%d",&available[i]); 
    }    
}
void get1D(int arr[10]){
	for (int i=0;i<n;i++)    
    {     
    	printf("%d\t",arr[i]);	 
    }   
	   
}
void get2D(int arr[10][10]){
	for (int i=0;i<n;i++)    
    {    
    	
        for (int j=0;j<m;j++)    
        {    
        	printf("%d\t",arr[i][j]);
        }   
        printf("\n");
		 
    }   
	   
}

int main(){
	printf("give allocation:\n");
	getAlloc();
	printf("give max:\n");
	getMax();
	printf("give available:\n");
	getAvailable();
	printf("calculating need matrix\n");
	printf("==========Allocation==========\n");	
	get2D(alloc);
	printf("==========Max==========\n");
	get2D(max);
	printf("==========Need Matrix==========\n");
	getNeed();
	get2D(need);
	printf("==========Available==========\n");	
	getAvailable();		
	return 0;
}
