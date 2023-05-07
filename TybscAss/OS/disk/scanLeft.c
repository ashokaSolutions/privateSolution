#include<stdio.h>
//just start subtracting on index at a time
//this is for right
int subChecker(int x,int y){
	if(x>y || x==y)
		return x-y;
	else 
		return y-x;

}

void accept(int arr[],int n){
	printf("give inputs:");
	for(int i=0;i<n;i++){
		printf("\ngive %d element:",i+1);
		scanf("%d",&arr[i]);
	}
}

void bubble(int a[], int n) // function to implement bubble sort  
 {  
   int i, j, temp;  
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
 }  

void calculations(int arr[],int head,int length){
	bubble(arr,length);
	for(int j=0;j<length;j++){
		printf("%d ",arr[j]);
	}
	int seek=0,i,ini,flag=0;
	for(i=0;i<length;i++){
		if(head<arr[i]){
			flag=1;
			ini=i;
			
			break;
		}
	}
	if(flag==1){
		while(i>=0){
			printf("\n%d)seek:%d\t head=%d\t arr[i]=%d\n",i,seek,head,arr[i-1]);
			seek+=subChecker(head,arr[i-1]);
			head=arr[i-1];
			i--;
		}
		seek+=subChecker(head,0);
		head=0;
		while(ini<length){
			printf("\n%d)seek:%d\t head=%d\t arr[i]=%d\n",i,seek,head,arr[ini]);
			seek+=subChecker(head,arr[ini]);
			head=arr[ini];
			ini++;
		}
		
	}
	printf("Total seek:%d\n",seek);
}

int main(){
	int arr[25],head,length;
	printf("give length of the array:");
	scanf("%d",&length);
	accept(arr,length);
	printf("\nGive head:");
	scanf("%d",&head);
	
	calculations(arr,head,length);
	
}
