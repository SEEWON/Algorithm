// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <stdio.h>
#include <stdlib.h>

//자식들 중에 추출(직접)
int max(int *nums, int numsSize, int i, int j, int k)
{
	int m = i;
	if (j < numsSize && nums[j] > nums[m])
	{
		m = j;
	}
	if (k < numsSize && nums[k] > nums[m])
	{
		m = k;
	}
	return m;
}

// 힙을 내려가며 큰 놈 추출
void downheap(int *nums, int numsSize, int i)
{
	while (1)
	{
		int j = max(nums, numsSize, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
		{
			break;
		}
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
		i = j;
	}
}

void heapsort(int *nums, int numsSize)
{
	int i;

	//크기를 줄여가며 힙 구성
	for (i = (numsSize - 2) / 2; i >= 0; i--)
	{
		downheap(nums, numsSize, i);
	}

	//제일 큰 수부터 배열의 역순으로 정렬
	for (i = 0; i < numsSize; i++)
	{
		int t = nums[numsSize - i - 1];
		nums[numsSize - i - 1] = nums[0];
		nums[0] = t;
		downheap(nums, numsSize - i - 1, 0);
	}
}

int findKthLargest(int *nums, int numsSize, int k)
{
	if (k > numsSize)
		return 0;
	heapsort(nums, numsSize);
	return nums[numsSize - k];
}

void main()
{

	int nums[8] = {3, 1, 2, 6, 5, 8, 7, 11};
	int numsSize = 8;
	int k = 2;

	printf("%d\n", findKthLargest(nums, numsSize, k));

	return;
}