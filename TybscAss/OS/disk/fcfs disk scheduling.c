#include<stdio.h>
//just start subtracting on index at a time

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
int main(){
	int arr[25],head,length;
	printf("give length of the array:");
	scanf("%d",&length);
	accept(arr,length);
	printf("\nGive head:");
	scanf("%d",&head);
	int seek=0;
	for(int i=0;i<length;i++){
			printf("\n%d)seek:%d\t head=%d\t arr[i]=%d\n",i,seek,head,arr[i]);
			seek+=subChecker(head,arr[i]);
			head=arr[i];
	}
	printf("Total seek:%d\n",seek);
}
