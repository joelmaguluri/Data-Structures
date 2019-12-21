#include <stdio.h>
#include <stdlib.h>

typedef struct array{
int * arr;
int size;
int length;
}Array;

void Display(Array *arr){
 printf("Elements entered are\n");
 for(int i=0;i<arr->length;i++)
  {
      printf("%d\n",arr->arr[i]);
  }
}
void Append(Array *arr,int n)
{
   if(arr->length<arr->size)
   {
       arr->arr[arr->length]=n;
       arr->length++;
   }
   else
   {
       printf("array index out of bound");
   }
   
}
void Insert(Array *arr,int index,int n)
{
  if(arr->length<arr->size)
  {
     if(index<=arr->length-1)
     {
        for(int i=arr->length;i>index;i--)
        {
            arr->arr[i]= arr->arr[i-1];
        }
        arr->arr[index]=n;
        arr->length++;
     }
     else
     {
         printf("Not possible");
     }

  }
  else
  {
       printf("array index out of bound");
  }
  

}

int BinarySearch(Array *arr,int key)
{
   int l=0;
   int h=arr->length-1;
   int mid=0;
   while(l<=h)
   {
       mid=(l+h)/2;
       if(arr->arr[mid]==key)
        return mid;
       else if (key<arr->arr[mid])
        {
           h=mid-1;
        }
        else
        {
          l=mid+1;
        }
        
   }
   return -1;
}

void main(){
 Array *arr=(Array *)malloc(sizeof(Array));
  int n,key;
  printf("enter size of the array");
  scanf("%d",&arr->size);
  arr->length=0;
  printf("enter number of elements to be inserted into the array");
  scanf("%d",&n);
  arr->arr=(int*)malloc(sizeof(int)*n);
  for(int i=0;i<n;i++)
  {
      scanf("%d",&arr->arr[i]);
      arr->length++;
  }
  printf("Enter key to search the array");
  scanf("%d",&key);
  int index=BinarySearch(arr,key);
  if(index!=-1)
    printf("%d found at index %d",key,index);
  else
  {
    printf("Key not found");
  }
  

}