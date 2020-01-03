#include <stdio.h>
void Display(int *arr,int length){
 for(int i=0;i<length;i++)
  {
      printf("%d\n",arr[i]);
  }
}
void ZigZag(int *arr,int size)
{
  for(int i=0;i<size-1;i++)
  {
    if(i%2==0)
    {
       if(arr[i]>arr[i+1])
       {
         int temp=arr[i];
         arr[i]=arr[i+1];
         arr[i+1]=temp;
       }
    }
    else
    {
      if(arr[i]<arr[i+1])
       {
         int temp=arr[i];
         arr[i]=arr[i+1];
         arr[i+1]=temp;
       }
    }
    
  }
  Display(arr,size);
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
ZigZag(arr,n);
}