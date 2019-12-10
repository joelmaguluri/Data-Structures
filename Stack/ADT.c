#include <stdio.h>
#include <stdlib.h>
struct Stack
{
   int size;
   int curr_size;
   struct Node *top;

}*stack;
struct Node 
{
   int value;
   struct Node *next;
}

int IsEmpty(struct Stack *s)
{
   if(s->size!=NULL)
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
  
  if(stack->curr_size!=stack->size)
   {
        struct Node *p=(struct Node *)malloc(sizeof(Node));
        scanf("%d",&p->value);
        p->next=stack->top;
        stack->top=p;
        p=NULL;
        stack->curr_size++;
   }
}
void Pop(struct Stack *s)
{
   struct Node *p= stack->top->next;
   stack->top=NULL;
   stack->top=p;
   p=NULL;
   stack->curr_size--;
}

void Peek(struct Stack *s, int index)
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
    return NULL;

}
void Create(struct Stack *s, int n)
{
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
        struct Node *p=(struct Node *)malloc(sizeof(Node));
        scanf("%d",&p->value);
        p->next=stack->top;
        stack->top=p;
        p=NULL;
        stack->curr_size++; 
      }
   }
   return s;
}

void main()
{
  
  stack=(struct Stack *)malloc(sizeof(Stack));
  scanf("%d",&stack->size);
  stack->top=NULL;
    
}