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
   int precedence;
   struct Node *next;
};

void Push(char c, int precedence)
{
   struct Node *p=(struct Node *)malloc(sizeof(struct Node));
   p->value=c;
   p->precedence=precedence;
   p->next=s->top;
   s->top=p;
   s->curr_size++;
}
char Pop()
{
    struct Node *temp;
    if(s->top!=NULL)
    {
       temp=s->top;
       s->top=s->top->next;
       s->curr_size--;
    }

    if(temp!=NULL)
        return temp->value;
    else
    {
         return '^';
    }


}

int is_operand(char c)
{
    if(65<=(int)c<=85|| 97<=(int)c<=122)
      return 1;
    else 
      return 0;
}
int Precedence(char c)
{
     if(c=='*'||c=='/')
      return 2;
     else if (c=='+'||c=='-')
      return 1;
     else 
      return 0;
}
void main()
{
    char *str="";
    char res_str[strlen(str)];
    int size =0;
    s=(stack *)malloc(sizeof(stack *));
    s->curr_size=0;
    s->size=strlen(str);
    s->top=NULL;
    int i=0;
    while(str[i]!='\0')
    {
      if(is_operand(str[i]))
        res_str[size++];
      else 
        if(s->top->precedence<=Precedence(str[i]))
        res_str[size++]=Pop();
        else 
         {
             Push(str[i],Precedence(str[i]));
         }
      i++;
    }
    printf("%s",res_str);
   
}

