#include <stdio.h>
#include <string.h>
int IsAnagram(char *str1,char*str2)
{
  int s1_hash=NULL,s2_hash=NULL,res=0;
  if(strlen(str1)!=strlen(str2))
  {
    return res;
  }
  else
  {
      for(int i=1;i<strlen(str1);i++)
      {
          if(i==1)
          {
            s1_hash=str1[i-1]^str1[i];
            s2_hash=str2[i-1]^str2[i];
          }
          else
          {
            s1_hash=s1_hash^str1[i];
            s2_hash=s2_hash^str2[i];
          }
          
      }
      res=(s1_hash==s2_hash)?1:0;
    
  }

  return res;

}
void main(){
 char *s1="sudeep";
 char *s2="psudee";
 if(IsAnagram(s1,s2))
 {
   printf("string 1 and string 2 are anagrams");
 }
 else
 {
   printf("string 1 and string 2 are not anagrams");
 }
 

}