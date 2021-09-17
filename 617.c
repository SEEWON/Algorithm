// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

// Return the merged tree.

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

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2)
{
  if (!root1 && !root2)
    return NULL;
  else if (!root1)
    return root2; //root1->val=0으로 했더니 오류 남
  else if (!root2)
    return root1;
  struct TreeNode *new = newNode(root1->val + root2->val);
  new->left = mergeTrees(root1->left, root2->left);
  new->right = mergeTrees(root1->right, root2->right);

  return new;
}

void main()
{
  return;
}