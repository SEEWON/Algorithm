// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include <stdio.h>
int majorityElement(int *nums, int numsSize)
{
    int count = 0, result;
    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
            result = nums[i];
        if (result == nums[i])
            count++;
        else
            count--;
    }
    return result;
}

void main()
{
    int nums[5] = {1, 3, 3, 2, 2};
    printf("%d\n", majorityElement(nums, 5));
    return;
}