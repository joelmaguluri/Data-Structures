#include <stdio.h>
int Give_Max_Flip_Score(int *arr,int size){
  int start=-1,end=-1;
  int score=0,zc=0;
  while(end<size)
  { 
    if(zc<=1)
    {
      if(arr[end]==0)
       zc++;
      end++;
    }
    if(zc>1)
    {
      if(arr[start]==0)
      {
        zc--;
      }
      start++;
    }
    if(end-start>score)
    {
      score=end-start;
    }
    
  }
  return score;

}
void main(){
  int n;//size of array 
  printf("Enter size of the array\n");
  scanf("%d",&n);
  printf("Enter sequence of 1's and 0's into the array\n");
  int arr[n];
  for (int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("score is %d ",Give_Max_Flip_Score(arr,n));
}