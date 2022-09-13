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
    // 1 2 3 4 5 6 
    
    
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL, *next = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        // ListNode* dummy = ListNode();
        // dummy->next = head;
        ListNode* l1 = head;
        ListNode *slow = head, *fast = head->next;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = slow->next;
        slow->next = NULL;
        l2 = reverse(l2);
        
        ListNode* temp, *temp2;
        while(l1 and l2){
            temp = l1->next;
            temp2 = l2->next;
            l1->next = l2;
            l2->next = temp;
            l1 = temp;
            l2 = temp2;            
        }
        
    }
};