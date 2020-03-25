int findDuplicate(int* nums, int numsSize){
int hashArray[numsSize],duplicate=0;
for(int i=0;i<numsSize;i++)
{
    hashArray[i]=0;
}
for(int i=0;i<numsSize;i++)
{
   hashArray[nums[i]-1]=hashArray[nums[i]-1]+1;
   
}
for(int i=0;i<numsSize;i++)
{
   if(hashArray[i]>1)
       duplicate=i+1;
}
 return duplicate;


}



