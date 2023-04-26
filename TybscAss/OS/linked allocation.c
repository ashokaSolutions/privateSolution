#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct dir{
	char filename[20];
	int start;
	struct dir *next;
}node;

node *newnode,*temp,*head,*last,*prev;
int freeBlocks;

int freeCal(int bit[],int n){
	int block=0;
	for(int i=0;i<n;i++){
		if(bit[i]==1)
			block++;
	}
	return block;
}

void generateBit(int bit[],int n){
	int num;
	for(int i=0;i<n;i++){
		num=rand();
		bit[i]=num%2;
	}
}

void fileShow(){
    printf("\nFilename\tStart\n");
    temp=head;
    while(temp){
        printf("%s\t%d\n",temp->filename,temp->start);
        temp=temp->next;
    }
}

void showBit(int bit[],int n){
	printf("Bit vector:\n");
	for(int i=0;i<n;i++){
		printf("%d ",bit[i]);
	}
	printf("\n");
}

void deleteFile(int bit[]){
	char filename[20],start;
	printf("enter filename:\n");
	scanf("%s",filename);
	head=temp;
	if(head==NULL){
		printf("dir empty\n");
	}	
	else{
		while(temp!=NULL){
			if(strcmp(temp->filename,filename)){
				start=temp->start;
				if(temp!=head){
					prev->next=temp->next;
				}else{
					head=temp->next;
				}
				int i=start;
				int j;
				while(bit[i]!=-1){
					j=bit[i];
					bit[i]=1;
				}			
				bit[i]=1;	
				free(temp);
				temp=NULL;
			}else{
				prev=temp;
				temp=temp->next;
			}
		}
	}
}

void create(int bit[],int n){
	char filename[20];
	int size;
	int freeBlocks=freeCal(bit,n);
	printf("enter filename:\n");
	scanf("%s",filename);
	printf("enter number of blocks needed:\n");
	scanf("%d",&size);
	if(size>freeBlocks){
		printf("the size is larger than available");
		return;
	}	
	int i;
	if(head!=NULL)
		i=0;
	else
		i=1;
	for(;i<n;i++){
		if(bit[i]==1){
			printf("start:%d\n",i);
			break;
		}
	}
	
	printf("newnode\n");
	newnode=(node *)malloc(sizeof(node));
	strcpy(newnode->filename,filename);
	newnode->start=i;
	//linked formed
	newnode->next=NULL;
	if(head==NULL){
		head=last=newnode;
		printf("\nif->%s\n",head->filename);
	}else{
		printf("\nelse->%s\n",head->filename);
		last->next=newnode;
		last=last->next;
	}
	printf("block contrrol");
	//block cancel
	freeBlocks=freeBlocks-size;
	int front=i+1;
	while(size>0){
		if(bit[front]==1){
			printf("in loop");
			bit[i]=front;
			i=front;	
			size--;
		}
		
		front++;
	}	
	bit[i]=-1;
	printf("file created successfully");

}

int main(){
	int bit[200],n;
	printf("give total number of blocks:\n");
	scanf("%d",&n);
	generateBit(bit,n);
	showBit(bit,n);
	int choice;
	while(1){
		printf("\n========MENU========\n1)show vector\n2)create\n3)show directory\n45delete\n)exit\nenter choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:showBit(bit,n);
					break;
			case 2:create(bit,n);
					break;	
			case 3:fileShow();
					break;
			case 4:deleteFile(bit);
					break;
			case 5:exit(0);
					break;
		}
	}
	return 0;
}
