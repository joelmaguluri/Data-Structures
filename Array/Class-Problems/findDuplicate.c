/*
Problem Statement:
Given an array of n+1 elements in range 0 to n-1 find the element which is duplicate*/
#include <stdio.h>
int Find_DUP(int *arr,int size){
  int val1,val2,max=(arr[0]>=0)?arr[0]:0;
  for(int i=1;i<size;i++)
  {
     if(arr[i]>max)
        max=arr[i];
     if(i==1)
     {
       val2=arr[i-1]^arr[i];
     }
     else
     {
       val2=val2^arr[i];
     }
  }
  val1=arr[0];
  for(int i=1;i<=max;i++)
  {
      val1=val1^arr[i];
  }
   
   return val1^val2;
}
void main(){
  int n;//size of array 
  printf("Enter size of the array\n");
  scanf("%d",&n);
  printf("Enter Elements of the array\n");
  int arr[n];
  for (int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Duplicate element is %d",Find_DUP(arr,n));
}
