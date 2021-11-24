// Given the root of a binary tree, return the sum of values of its deepest leaves.

#include <stdio.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxDepth, sum = 0;
void countDepth(struct TreeNode *root, int depth)
{
  if (root == NULL)
    return;
  if (maxDepth == depth)
    sum += (root->val);
  if (maxDepth < depth)
  {
    maxDepth = depth;
    sum = root->val;
  }
  countDepth(root->left, depth + 1);
  countDepth(root->right, depth + 1);
  return;
}

int deepestLeavesSum(struct TreeNode *root)
{
  maxDepth = 0; //전역변수에서 maxDepth =0; 초기화하고 이 줄 안썼더니 오류 발생..왜?
  countDepth(root, 0);
  return sum;
}

void main()
{
  return;
}