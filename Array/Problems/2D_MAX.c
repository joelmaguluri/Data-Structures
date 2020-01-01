#include <stdio.h>
int n;
int GIVE_MAX_ROW(int arr[][n],int n)
{
  int i=0,j=n-1;
  int max;
   while(j!=-1&&i!=n)
   {
     if(arr[i][j]==0)
     {
       printf("%d",arr[i][j]);
       i++;
     }
     else
     {

       printf("%d",arr[i][j]);
       j--;
     }
     max=i;
   }
   printf("max row is %d",max);
    if(max!=n)
      return max;
    else 
      return max-1;

}
void main()
{
  printf("Enter Dimensions");
  scanf("%d",&n);
  printf("Entered %d*%d array\n",n,n);
  int arr[n][n];
  printf("Enter Elements now\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }
 int res= GIVE_MAX_ROW(arr,n);
 printf("Row with max 1's is %d",res);

}