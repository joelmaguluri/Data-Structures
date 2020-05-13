

int removeDuplicates(int *nums, int numsSize)
{

  if (numsSize <= 0)
    return numsSize;
  int curr = nums[0];
  for (int i = 1; i < numsSize; i++)
  {
    if (nums[i] != curr)
      curr = nums[i];
    else
      nums[i] = nums[0];
  }
  int index = 1;
  for (int i = index; i < numsSize; i++)
  {
    if (nums[i] != nums[0])
      nums[index++] = nums[i];
  }
  return index;
}