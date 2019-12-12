#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
   int size;
   int curr_size;
   struct Node *top;

}stack;
stack *s;
struct Node 
{
   char value;
   struct Node *next;
};
void Push(char c)
{
   struct Node *p=(struct Node *)malloc(sizeof(struct Node));
   p->value=c;
   p->next=s->top;
   s->top=p;
   s->curr_size++;
}
void Pop()
{
    if(s->top!=NULL)
    {
       s->top=s->top->next;
       s->curr_size--;
    }
  

}


int ParathesisMatch(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {

      if(str[i]=='(')
       Push('(');
      else if (str[i]==')')
       Pop();
      else
       continue;
      
    }
   if(s->top==NULL)
      return 1;
   else 
      return 0;
  
}

int main()
{
  int n,size;
  printf("Enter number of charecters you want to enter");
  scanf("%d",&n);
  char str[n];
  printf("Enter string to check paranthesis match");
  scanf("%s",str);
  s=(stack *)malloc(sizeof(stack));
  s->curr_size=0;
  s->size=n;
  s->top=NULL;
  if(ParathesisMatch(str))
  {
    printf("Paranthesis Matched");
  }
  else
  {
   printf("Miss Match");
  }
  
}

