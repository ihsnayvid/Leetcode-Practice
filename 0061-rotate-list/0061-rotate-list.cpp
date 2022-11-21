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
    int count(ListNode* head){
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        return n;
    }
//     ListNode* reverse(ListNode* head){
//         ListNode * curr = head, next = NULL, prev = NULL;
        
//         while(curr){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = count(head);
        k = k % n;
        if(!head or n == 1 or k == 0 or k == n) return head;
        k = n - k;
        
        ListNode* temp = head;
        while(--k)
            temp = temp->next;
        ListNode* second = temp->next;
        temp->next = NULL;
        
        
        ListNode* dummy = new ListNode(0);
        dummy->next = second;
        
        while(second->next)
            second = second->next;
        second->next = head;
        
        return dummy->next;
        
    }
};