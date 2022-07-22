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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode *dummy = first, *dummy2 = second;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                first->next = temp;
                first = first->next;
            }
            else{
                second->next = temp;
                second = second->next;
            }
            temp = temp->next;
        }
        second->next = NULL;
        first->next = dummy2->next;
        return dummy->next;
    }
};