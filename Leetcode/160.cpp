/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> hashmap;
        ListNode *curr = headA;
        while(curr) {
            hashmap[curr]++;
            curr=curr->next;
        }
        curr = headB;
        while(curr) {
            if(hashmap[curr]>0) return curr;
            curr = curr -> next;
        }
        return nullptr;
    }
};