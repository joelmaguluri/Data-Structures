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

void Delete(Array *arr,int index)
{

   if(index>arr->length-1)
   {
       printf("Index out of bound");
   } 
   else
   {
      for(int i=index;i<arr->length-1;i++)
      {
          arr->arr[i]=arr->arr[i+1];
      }
      arr->length--;
   }
   
}

void main()
{
  Array *arr=(Array *)malloc(sizeof(Array));
  int n;
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
  
  printf("Before Insertion:\n");
  Display(arr);
  Insert(arr,2,3);
  printf("After Insertion:\n");
  Display(arr);
  Delete(arr,1);
  Display(arr);
}
