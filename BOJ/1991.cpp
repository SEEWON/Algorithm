#include <cstdlib>
#include <iostream>

using namespace std;

class node {
 public:
  char val;
  node *leftChild;
  node *rightChild;
};

node *find(node *now, char lookingFor) {
  // 여기 찾기함수 고치기
  if (now->val == lookingFor) return now;
  node *leftTemp = NULL, *rightTemp = NULL;
  if (now->leftChild) leftTemp = find(now->leftChild, lookingFor);
  if (now->rightChild) rightTemp = find(now->rightChild, lookingFor);
  if (leftTemp != NULL)
    return leftTemp;
  else if (rightTemp != NULL)
    return rightTemp;
  else
    return NULL;
}

void preorder(node *now) {
  cout << now->val;
  if (now->leftChild) preorder(now->leftChild);
  if (now->rightChild) preorder(now->rightChild);
}
void inorder(node *now) {
  if (now->leftChild) inorder(now->leftChild);
  cout << now->val;
  if (now->rightChild) inorder(now->rightChild);
}
void postorder(node *now) {
  if (now->leftChild) postorder(now->leftChild);
  if (now->rightChild) postorder(now->rightChild);
  cout << now->val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  node *root = (node *)malloc(sizeof(node));
  root->val = 'A';
  root->leftChild = NULL;
  root->rightChild = NULL;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char root_i, left_i, right_i;
    cin >> root_i >> left_i >> right_i;
    node *temp = find(root, root_i);
    if (left_i != '.') {
      temp->leftChild = (node *)malloc(sizeof(node));
      temp->leftChild->val = left_i;
      temp->leftChild->leftChild = NULL;
      temp->leftChild->rightChild = NULL;
    }
    if (right_i != '.') {
      temp->rightChild = (node *)malloc(sizeof(node));
      temp->rightChild->val = right_i;
      temp->rightChild->leftChild = NULL;
      temp->rightChild->rightChild = NULL;
    }
  }
  preorder(root);
  cout << endl;
  inorder(root);
  cout << endl;
  postorder(root);
  cout << endl;

  return 0;
}