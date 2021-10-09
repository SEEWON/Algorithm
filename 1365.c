// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

// Return the answer in an array.

#include <stdio.h>
#include <stdlib.h>

int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
  int *res = (int *)malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  int cnt = 0;
  for (int i = 0; i < numsSize; i++)
  {
    for (int j = 0; j < numsSize; j++)
    {
      if (nums[i] > nums[j])
      {
        cnt++;
      }
    }
    res[i] = cnt;
    cnt = 0;
  }
  return res;
}

void main()
{
  int nums[5] = {8, 1, 2, 2, 3};
}