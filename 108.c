// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeNode *newNode(int val)
{
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct TreeNode *ArrayToBST(int *nums, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left = ArrayToBST(nums, start, mid - 1);
    root->right = ArrayToBST(nums, mid + 1, end);
    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    return ArrayToBST(nums, 0, numsSize - 1);
}

void main()
{
    int nums[5] = {1, 2, 3, 4, 5};

    struct TreeNode *Value = sortedArrayToBST(nums, 5);

    return;
}