#include <stdio.h>
int MissingElement(int *arr, int size)
{
  int min=arr[0],max=arr[0],res1,res2;
  for(int i=1;i<size;i++)
  { 
    if(i==1)
    {
      res1=arr[i-1]^arr[i];
    }
    else
    {
      res1=res1^arr[i];
    }
    if(arr[i]<min)
     min=arr[i];
    if(arr[i]>max)
     max=arr[i];
  }
  res2=min;
  for(int i=min+1;i<=max;i++)
  {
    res2=res2^i;
  }
  return res1 ^ res2;
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
  printf("The Missing element in the array is %d",MissingElement(arr,n));
}