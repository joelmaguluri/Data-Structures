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

int Search(Array *arr,int key)
{
    int index=-1;
    for(int i=0;i<arr->length;i++)
    {
        if(arr->arr[i]==key)
         index=i;
    }

    return index;

}
void main()
{
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
  int index=Search(arr,key);
  if(index!=-1)
    printf("%d found at index %d",key,index);
  else
  {
    printf("Key not found");
  }
  


}