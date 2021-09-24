// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* newNode() {
  struct ListNode* new = malloc(sizeof(struct ListNode));
  new->next = NULL;
  return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* ans = newNode();
  struct ListNode* HeadPointer = ans;

  int sum, over10 = 0;
  for (int i = 0;; i++) {
    if (!l1 && !l2 && over10 == 0) {
      break;
    } else if (!l1 && !l2 && over10 == 1) {
      sum = 1;
      over10 = 0;
    } else if (!l1 && l2) {
      sum = l2->val;
      l2 = l2->next;
    } else if (l1 && !l2) {
      sum = l1->val;
      l1 = l1->next;
    } else {
      sum = l1->val + l2->val;
      l1 = l1->next;
      l2 = l2->next;
    }
    if (i > 0) {  //루프를 처음 돌 경우(i=0), 포인터 넘겨주지 않기 위해서
      ans->next = newNode();  // break하지 않았을 경우 다음 노드 생성
      ans = ans->next;
    }  //포인터 넘겨줌
    if (over10 == 1) {
      sum++;
      over10 = 0;
    }
    if (sum > 9) {
      over10 = 1;
      sum -= 10;
    }
    ans->val = sum;  //값 넣어줌
  }
  return HeadPointer;
}

void main() {
  struct ListNode* input1 = newNode();
  input1->val = 1;
  input1->next = newNode();
  input1->next->val = 9;
  input1->next->next = newNode();
  input1->next->next->val = 0;
  input1->next->next->next = newNode();
  input1->next->next->next->val = 3;
  // input1->next->next->next->next = NULL;

  struct ListNode* input2 = newNode();
  input2->val = 2;
  input2->next = newNode();
  input2->next->val = 1;
  input2->next->next = newNode();
  input2->next->next->val = 1;
  // input2->next->next->next = NULL;

  struct ListNode* ans = addTwoNumbers(input1, input2);
  return;
}