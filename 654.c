// You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

// 1. Create a root node whose value is the maximum value in nums.
// 2. Recursively build the left subtree on the subarray prefix to the left of the maximum value.
// 3. Recursively build the right subtree on the subarray suffix to the right of the maximum value.
// Return the maximum binary tree built from nums.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
  struct TreeNode *new = malloc(sizeof(struct TreeNode));
  new->val = val;
  new->left = NULL;
  new->right = NULL;
  return new;
}

int findMaxIndex(int *nums, int numsSize)
{
  int max = nums[0];
  int index = 0;
  for (int i = 1; i < numsSize; i++)
  {
    if (nums[i] > max)
    {
      max = nums[i];
      index = i;
    }
  }
  return index;
}

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
  if (numsSize == 0)
    return NULL;

  int maxIndex = findMaxIndex(nums, numsSize);

  struct TreeNode *new = newNode(nums[maxIndex]);
  new->left = constructMaximumBinaryTree(nums, maxIndex);
  new->right = constructMaximumBinaryTree(nums + maxIndex + 1, numsSize - maxIndex - 1);

  return new;
}

void main()
{
  int nums[6] = {3, 2, 1, 6, 0, 5};

  struct TreeNode *Value = constructMaximumBinaryTree(nums, 6);

  return;
}