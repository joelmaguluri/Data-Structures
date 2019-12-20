#include<stdio.h>
#include<string.h>
void main()
{
 char *m=str[i]+"";
    printf("%s",m);
    if(is_num(m))
    { 
        printf("hello");
        push(atoi(m));
    
    }
    else
    {
      printf("hii");
      int val1=pop();
      int val2=pop();
      printf("%d%d",val1,val2);
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