#include <stdio.h>
void Display(int *arr,int length){
 for(int i=0;i<length;i++)
  {
      printf("%d\n",arr[i]);
  }
}
void replace_array(int* arr,int length)
{
  int largest=-1;
  for(int i=length-1;i>=0;i--)
  {
    int temp=arr[i];
    arr[i]=largest;
    if(largest<temp)
    {
      largest=temp;
    }
  }
  Display(arr,length);

}
void main(){
int n;//size of array 
scanf("%d",&n);
int arr[n];
for (int i=0;i<n;i++)
{
  scanf("%d",&arr[i]);
}
replace_array(arr,n);

}