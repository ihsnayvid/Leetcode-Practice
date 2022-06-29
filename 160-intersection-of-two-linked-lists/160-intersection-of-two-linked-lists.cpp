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
        ListNode *d1 = headA, *d2 = headB;
        while(d1 or d2){
            if(!d1) d1 = headB;
            else if(!d2) d2 = headA;
            if(d1 == d2) return d1;
            d1 = d1->next;
            d2 = d2->next;            
        }
        return NULL;
    }
};