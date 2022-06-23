/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *l1, *l2;
        if(list1->val < list2->val) l1 = list1, l2 = list2;
        else l1 = list2, l2 = list1;
        
        ListNode* res = l1;
        
        while(l1 and l2){
            ListNode* temp = NULL;
            while( l1 and l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            ListNode* t = l1;
            l1 = l2;
            l2 = t;
        }
        
        return res;
    }
};