/******************************************************************************

Title    : Binary and sequential Search
Author   : Deepak M S 
Date     : 10/08/2021
Aim      : To write a C program to perform sequential and binary search using functions

*******************************************************************************/
#include <stdio.h>
//fuction for binery search
int bSearch(int array[],int size,int num);
//fuction for sequential search
int sSearch(int array[],int size,int num);
//gloabal variable
int i;

int main(){
    //variable declartion
    int array[50];
    int size,option,num,pos,j,temp;

    //read the size of array
    printf("Enter the size of the array:");
    scanf("%d",&size);
    
    //read the elements in array
    printf("\nEnter the elements in array:");
    for(i=0;i<size;i++){
        scanf("%d",&array[i]);
    }

    //print the array
    printf("\nElements in array:");
    for(i=0;i<size;i++){
        printf("\t%d",array[i]);
    }

    //sort the array
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(array[i]>array[j]){
                temp = array[i];
                array[i]= array[j];
                array[j]= temp;
            }
        }
    }

    printf("\nElements in array After sorting :");
    for(i=0;i<size;i++){
        printf("\t%d",array[i]);
    }


    //Read the number want to search
    printf("\n\n Enter the number want to search:");
    scanf("%d",&num);
    
    //Ask the user to which search to perform
    printf("\n Enter the serach want to perform \n\t 1 for Binery Search \n\t 2 for Sequential Search");
    printf("\n Enter your option:");
    scanf("%d",&option);

    switch (option)
    {
    case 1:
        pos = bSearch(array,size,num);
        if(pos == -1){
            printf("\n Number Not found!!");
        }else{
            printf("\n%d find at the %dth position",num,(pos+1));
        }
        
        break;
    case 2:
        
        pos = sSearch(array,size,num);
        if(pos == -1){
            printf("\n Number Not found!!");
        }else{
            printf("\n%d find at the %dth position",num,(pos+1));
        }
        break;
    
    default:
        printf("\nInvalid Option");
        break;
    }

    return 0;
}

int bSearch(int array[],int size,int num){
    int l,r,mid;
    l=0;
    r=size-1;
    
    while(l<=r){
        mid = (l+r)/2;
        if(array[mid] == num ){
            return mid;
        }else if(num < array[mid]){
            r = mid -1;
        }else{
            l = mid +1;
        }
    }

    return -1;
}

int sSearch(int array[],int size,int num){
    for(i=0;i<size;i++){
        if(array[i]==num){
            return i;
        }
    }

    return -1;
}