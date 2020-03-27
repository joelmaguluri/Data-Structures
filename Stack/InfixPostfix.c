#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
   int size;
   int curr_size;
   struct Node *top;
   int precedence;

}stack;
stack *s;
int size =0;
struct Node 
{
   char value;
   struct Node *next;
};
char* substr(const char *src, int m, int n)
{
	// get length of the destination string
	int len = n - m;

	// allocate (len + 1) chars for destination (+1 for extra null character)
	char *dest = (char*)malloc(sizeof(char) * (len + 1));

	// extracts characters between m'th and n'th index from source string
	// and copy them into the destination string
	for (int i = m; i < n && (*src != '\0'); i++)
	{
		*dest = *(src + i);
		dest++;
	}

	// null-terminate the destination string
	*dest = '\0';

	// return the destination string
	return dest - len;
}

int is_operand(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
      return 0;
    else 
      return 1;
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
void Push(char c, int precedence)
{
   struct Node *p=(struct Node *)malloc(sizeof(struct Node));
   p->value=c;
   s->precedence=precedence;
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
       if(s->top==NULL)
        s->precedence=0;
       else 
       s->precedence=Precedence(s->top->value);
    }

    if(temp!=NULL)
        return temp->value;
    else
    {
         return '^';
    }

}

void PopMech(char *res_str,char c)
{
  while(Precedence(c)<=s->precedence)
  {
        
      res_str[size++]=Pop();
             
  }
   Push(c,Precedence(c));
  
}

void main()
{
    char *str="a+b*c-d/e";
    char res_str[strlen(str)];
    s=(stack *)malloc(sizeof(stack *));
    s->curr_size=0;
    s->size=strlen(str);
    s->top=NULL;
    s->precedence=0;
    for(int i=0;i<strlen(str);i++)
    {
      if(is_operand(str[i]))
       
       {
          res_str[size++]=str[i];
       } 
      else
      { 
        PopMech(res_str,str[i]);
       }
      
    }
    /*while(size<=strlen(str))
    {
      res_str[size++]=Pop();
    }
    */
   while(size<=strlen(str))
   {
     res_str[size++]=Pop();
  
   }
    printf("%s",substr(res_str,0,strlen(str)));
   
}

