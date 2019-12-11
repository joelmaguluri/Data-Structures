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
   char value;
   struct Node *next;
};
void Push(struct Stack *s)
{
  
  if(s->curr_size!=s->size)
   {
        struct Node *p=(struct Node *)malloc(sizeof(struct Node));
        scanf("%c",&p->value);
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

struct Stack * Create(int n)
{
   
   struct Stack *s =(struct Stack *)malloc(sizeof(struct Stack));
   scanf("%d",&s->size);
   s->curr_size=0;
   s->top=NULL;
   return s;
}
int ParathesisMatch(char *str, struct Stack *stack)
{
    for(int i=0;str[i]!='\0';i++)
    {
       if(str[i]=='(')
       {
           push('(');
       }
       else if (str[i]==')')
       {
           pop();
       }
       else 
        continue;
    }

    if(stack->top==NULL)
        return 1;
    else 
        return 0;

}

int main()
{
  
  int n;
  printf("Enter Number of charecters");
  scanf("%d",&n);
  struct Stack *stack=Create(n);
  int str[n];
  gets(str);
  int result=ParathesisMatch(str,stack);
  if(result)
   printf("Paranthesis Matched");
  else
   printf("Mismatch");
  return 0;
}