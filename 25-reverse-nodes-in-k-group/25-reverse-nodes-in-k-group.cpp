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
    int countNodes(ListNode* head){
        ListNode* temp = head;
        int ans = 0;
        while(temp){
            ans ++;
            temp = temp->next;
        }
        return ans;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k == 1) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* pre = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        
        int count = countNodes(head);
        ListNode *curr, *next;
        while(count >= k){
            curr = pre->next;
            next = curr->next;
            for(int i=1; i<k; i++){
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            count -= k;
            pre = curr;            
        }
                                                                                                               return dummy->next;           
    }
};