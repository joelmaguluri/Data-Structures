#include <stdio.h>
#include <stdlib.h>

int *spannedarray(int *arr, int n)
{
  int stack[n], i = -1, index = 0;
  int *result = (int *)malloc(sizeof(int) * n);
  stack[++i] = arr[index++];
  result[index - 1] = (index - 1) - (i - 1);
  while (index < n)
  {
    if (arr[index] <= stack[i])
    {
      result[index] = index - i;
      stack[++i] = arr[index];
    }
    else
    {
      printf("before top %d\n", i);
      while (arr[index] > stack[i])
      {
        i--;
      }
      printf("top %d\n", i);
      result[index] = index - i;
      stack[++i] = arr[index];
    }
    index++;
  }

  return result;
}

void main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int *res = spannedarray(arr, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", res[i]);
  }
}