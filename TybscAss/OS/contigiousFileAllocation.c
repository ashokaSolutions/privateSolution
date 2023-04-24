//I) Write a program to simulate Sequential (Contiguous) file allocation method. Assume disk
//with n number of blocks. Give value of n as input. Write menu driver program with menu
//options as mentioned above and implement each option.
//NOTE:WHILE DELETING 0 IS NOT GOING TO 1 THIS NEEDS HELP
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<malloc.h>

//make structure(single linked list)
struct dir{
    char filename[20];
    int start;
    int len;
    struct dir *next;
};
//d is actual linked list
struct dir *d,*newnode,*lastnode,*temp,*prev;

//generate the array like 1 0 0 1
void generateBit(int bit[],int n){
    int num;
    for(int i=0;i<n;i++){
        num=rand();
        bit[i]=num%2;
    }
}

//display it
void showBit(int bit[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",bit[i]);
}

//showing what is in the list
void showDir(){
    printf("\nFilename\tStart\tlength\n");
    temp=d;
    while(temp){
        printf("%s\t%d\t%d\n",temp->filename,temp->start,temp->len);
        temp=temp->next;
    }
}

//creation
//ex:0 0 0 1 1 1 0 1 0 1 1 1 1 0
void createFile(int bit[],int n){
    char filename[20];
    int length,flag,tempVar,start;
    printf("\nenter filename:\n");
    scanf("%s",filename);
    printf("enter length:\n");
    scanf("%d",&length);
    //start from index zero of the bit till you find 1's in line that match the length
    for(int i=0;i<=n;i++){
    	//when you find your first 1
        if(bit[i]==1){
        	//give start their
           start=i;
           //flag=(means)=that you have found it
           flag=1;
           //now when u found it check for the length and traverse from there
          	for(int i=start;i<start+length;i++){
          		//while traversing 0 occurrese while the length is not statisfied then flag=0
                //flag==0,did not found it
		        if(bit[i]==0){
		            start=-1;
		            flag=0;
		            break;
		        }
	        }
        }
        //if you find the sequence of 1 that is staisfying the length break the for loop
        if(flag==1)
            break;
    }
    //if start is>-0(that means the length is satisfied)
    if(start>=0){
        printf("start:%d\n",start);
        //put the 1 to 0 to show that the file occupied it
         for(int i=start;i<start+length;i++){
		    bit[i]=0;
	    }
	    //create space for new node
        newnode=(struct dir *)malloc(sizeof(struct dir));
        //copy filename in newnode->file
        strcpy(newnode->filename,filename);
        //copy len and start to newfile
        newnode->len=length;
        newnode->start=start;
        //if the d is empty then this node will be the firstnode
        if(d==NULL){
            lastnode=d=newnode;
        }else{
        	//if this node is not first then put the node in last
            lastnode->next=newnode;
            lastnode=lastnode->next;
            printf("\nfile allocation is sexy");
            //the above three lines explained
            //now when new node comes it is named as lastnode aswell as d,but when after it other node comes it is-
            //-sticked after the lastnode and then the lastnode is now the node stciked after it
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
	//if dir is empty
	if(d==NULL)
		printf("\nerror\n");
	else{
		//if temp is not empty that means traverse can be done as their are nodes remainig
		while(temp!=NULL){
			//compare filenames,0 means yes ,-1 mean no
			if(strcmp(temp->filename,filename)==0){
				//if found then take start and len
				start=temp->start;
				length=temp->len;
				//if tempis not as start then unlink temp making the prev pointing to the next of temp
				if(temp!=d)
					prev->next=temp->next;
				else
					d=temp->next;//if temp is d then just make d point to temp next
				//free memory of temo
				free(temp);
				//make temp null
				temp=NULL;
				//break
				break;
			}else{
				//if not found keep seraching
				prev=temp;
				temp=temp->next;
			}
		}	
	}	
	printf("start:%d\n",start);
	printf("length:%d\n",length);
	//making 0 to 1
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
