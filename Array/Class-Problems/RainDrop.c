/*
Problem Statement:
Given n postive integer in an array where each represent a bar of width 1.
calculate how much water it is able to trap.
I/p: 1 3 0 1 2 0 4 1
o/p: 9 
*/
/*
  if(arr[i]==0)
    {
   
      if(arr[i-1]!=0)
      {
        int j=i,max_index=i;       
        while(j!=-1&&arr[j-1]!=0)
        { 
          if(arr[--j]>arr[max_index])
            {
              max_index=j;
            }
        }
        int index=max_index+1;
        while(index<=i)
        {
          score=score+(arr[max_index]-arr[index]);
          index++;
        }
      }
      else
      {
        if(arr[i]<arr[max_index])
        score=score+(arr[max_index]-arr[i]);
      } 

    }
      else
      {
        
      }


*/
#include <stdio.h>
int RainDropScore(int *arr,int size)
{
  int score=0,max_index=0,i=0;
  while(i<size)
  {
    if(arr[i]>=arr[max_index])
    {
      max_index=i;
    }
    if(arr[i]==0)
    {
      while(arr[i]<arr[max_index]&&i<size)
      {
        score=score+arr[max_index]-arr[i];
        i++;
      }
      if(i==size)
      {
        
        score=0;
      }
      max_index=i;
    }
    i++;
  }
  return score;
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
  printf("Rain Drop Score is %d",RainDropScore(arr,n));

}