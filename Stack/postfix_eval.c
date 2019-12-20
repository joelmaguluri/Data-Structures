#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
   int size;
   int curr_size;
   struct Node *top;

}stack;
struct Node 
{
   int value;
   struct Node *next;
};
stack *s;
int a_i(char *c)
{
   if(c=="0")
    return 0;
   else if (atoi(c)==0)
    return -1;
   else 
   return atoi((c));

}
void push(int val)
{
     struct Node*p=(struct Node*)malloc(sizeof(struct Node));
      p->value=val;
      p->next=s->top;
      s->top=p;
      s->curr_size++;
}
int pop()
{
    int val=s->top->value;
    s->top=s->top->next;
    s->curr_size--;
    return val;
}
int is_num(char *c)
{
  if(a_i(c)==-1)
   return 0;
  else
   return 1;  
}
void main()
{

  char *str="35*62/+4-";
  s=(stack *)malloc(sizeof(stack));
  s->size=strlen(str);
  s->curr_size=0;
  for(int i=0;i<strlen(str);i++)
  {
    char sg[2];
    sg[0]=str[i];
    sg[1]='\0';
     if(is_num(sg))
    { 
        
        push(atoi(sg));
      
    }
    else
    {
      
      int val1=pop();
      int val2=pop();
      if(str[i]=='/')
        push(val2/val1);
      else if (str[i]=='*')
        push(val2*val1);
      else if (str[i]=='+')
        push(val2+val1);
      else{
        push(val2-val1);
      }

    }

  }
  printf("final result is %d",s->top->value);
  
}