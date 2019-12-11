#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
   int size;
   int curr_size;
   struct Node *top;

};
struct Node 
{
   int value;
   struct Node *next;
};

int IsEmpty(struct Stack *s)
{
   if(s->curr_size==0)
   {
       return 1;
   }
   else
   {
       return 0;
   }

}

int IsFull(struct Stack *s)
{
   if(s->size==s->curr_size)
   {
       return 1;
   }
   else
   {

       return 0;
   }

}

void Push(struct Stack *s)
{
  
  if(s->curr_size!=s->size)
   {
        struct Node *p=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&p->value);
        p->next=s->top;
        s->top=p;
        p=NULL;
        s->curr_size++;
   }
}
void Pop(struct Stack *s)
{
   struct Node *p= s->top->next;
   s->top=NULL;
   s->top=p;
   p=NULL;
   s->curr_size--;
}

int Peek(struct Stack *s, int index)
{
    int curr_index=0;
    if(!IsEmpty(s))
     {
         struct Node *p=s->top;
        
         if(index!=0)
         {
            while(curr_index!=index)
            {
               p=p->next;
               curr_index++;
            }

         }
         return p->value;
         
     }
    return -1;

}
int Top(struct Stack *s)
{
   if(s->top!=NULL)
      return s->top->value;
   return -1;
  
}
struct Stack * Create(int n)
{
   
   struct Stack *s =(struct Stack *)malloc(sizeof(struct Stack));
   printf("Enter Size of Stack");
   scanf("%d",&s->size);
   s->curr_size=0;
   s->top=NULL;
   printf("enter number of elements to be inserted into stack");
   scanf("%d",&n);
   if(n>s->size)
   {
      printf("returning NULL as Size of stack exceeded");
      return NULL;
   }
   else
   {
      for(int i=0;i<n;i++)
      {
        struct Node *p=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&p->value);
        p->next=s->top;
        s->top=p;
        p=NULL;
        s->curr_size++; 
      }
   }
   return s;
}


void main()
{
  
  struct Stack *stack=Create(5);
  int n;
  printf("Enter Number of charecters");
  scanf("%d",&n);
  int str[n];
  gets(str);
  
}