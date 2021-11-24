// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

#include <stdio.h>

int maxSubArray(int *nums, int numsSize)
{
    int sum;
    int max = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        sum = nums[i];
        if (sum > max)
            max = sum;
        for (int j = i; j < numsSize - 1; j++)
        {
            sum += nums[j + 1];
            if (sum > max)
                max = sum;
        }
    }
    return max;
}

void main()
{
    int nums[5] = {5, 4, -1, 7, 8};
    int Value = maxSubArray(nums, 5);
    printf("%d\n", Value);
    return;
}