/*
Problem statement:
given an array of integer values update every element with the value which is 
product of previous and next element but in following cases do 
1) if index is 0 replace with a[i]*a[i+1]
2) if index is n-1 replace with a[i-1]*a[i]
*/
#include <stdio.h>
void ReplaceByMultiplying(int *arr, int size)
{ int temp;
  for(int i=0;i<size;i++)
  {
    if(i==0||i==size-1)
    {
      if(i==0)
      {
        temp=arr[i];
        arr[i]=arr[i]*arr[i+1];
      }
      else
      {
        arr[i]=temp*arr[i];
        printf("value of temp is %d",temp);
      }
    }
    else
    {
      int temp1=temp;
      temp=arr[i];
      arr[i]=temp1*arr[i+1];
    }
    
  }

}
void main()
{
  int n;//size of array 
  printf("Enter size of the array\n");
  scanf("%d",&n);
  printf("Enter Elements of the array\n");
  int arr[n];
  for (int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  ReplaceByMultiplying(arr,n);
  printf("Result after Replacing is \n");
  for(int i=0;i<n;i++)
  {
    printf("%d\t",arr[i]);
  }
}