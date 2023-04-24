//I) Write a program to simulate Sequential (Contiguous) file allocation method. Assume disk
//with n number of blocks. Give value of n as input. Write menu driver program with menu
//options as mentioned above and implement each option.
//NOTE:WHILE DELETING 0 IS NOT GOING TO 1 THIS NEEDS HELP
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<malloc.h>

struct dir{
    char filename[20];
    int start;
    int len;
    struct dir *next;
};

struct dir *d,*newnode,*lastnode,*temp,*prev;


void generateBit(int bit[],int n){
    int num;
    for(int i=0;i<n;i++){
        num=rand();
        bit[i]=num%2;
    }
}
void showBit(int bit[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",bit[i]);
}
void showDir(){
    printf("\nFilename\tStart\tlength\n");
    temp=d;
    while(temp){
        printf("%s\t%d\t%d\n",temp->filename,temp->start,temp->len);
        temp=temp->next;
    }
}

void createFile(int bit[],int n){
    char filename[20];
    int length,flag,tempVar,start;
    printf("\nenter filename:\n");
    scanf("%s",filename);
    printf("enter length:\n");
    scanf("%d",&length);
    for(int i=0;i<=n;i++){
        if(bit[i]==1){
           start=i;
           flag=1;
           tempVar=start;
           while(tempVar!=(start+length)){
                if(bit[tempVar]==0){
                    start=-1;
                    flag=0;
                    break;
                }
                tempVar++;
            }
        }
        if(flag==1)
            break;
    }
    int temp2;
    if(start>=0){
        tempVar=start;
        while(tempVar!=(start+length)){
                bit[tempVar]=0;
                tempVar++;
        }
        newnode=(struct dir *)malloc(sizeof(struct dir));
        strcpy(newnode->filename,filename);
        newnode->len=length;
        newnode->start=start;
        if(d==NULL){
            lastnode=d=newnode;
        }else{
            lastnode->next=newnode;
            lastnode=lastnode->next;
            printf("\nfile allocation is sexy");
        }
        
    }else
        printf("wronged!");
    
}
void deleteFile(int bit[]){
	int start=-1,length=-1;
	char filename[20];
	printf("\nenter filename to delete:\n");
	scanf("%s",filename);
	temp=d;
	if(d==NULL)
		printf("\nerror\n");
	else{
		while(temp!=NULL){
			if(strcmp(temp->filename,filename)==0){
				start=temp->start;
				length=temp->len;
				if(temp!=d)
					prev->next=temp->next;
				else
					d=temp->next;
				free(temp);
				temp=NULL;
				break;
			}else{
				prev=temp;
				temp=temp->next;
			}
		}	
	}	
	printf("start:%d\n",start);
	printf("length:%d\n",length);
	for(int i=start;i<start+length;i++){
		bit[i]=1;
	}
}
int main() {
    int bit[100],choice,n,b=1;
    d=NULL;
    printf("\nnumber of blocks:\n");
    scanf("%d",&n);
    generateBit(bit,n);
    showBit(bit,n);
    while(b){
        printf("\n=========Menu=========\n");
        printf("enter choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:showBit(bit,n);
                    break;
            case 2:createFile(bit,n);
                   break;
            case 3:deleteFile(bit);
            		showBit(bit,n);
            		break;
            case 4:showDir();
            		break;
        }
    }

    return 0;
}
