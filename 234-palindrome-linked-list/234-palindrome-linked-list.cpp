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
    
    ListNode *reverse(ListNode *head){
        ListNode* curr = head;
        ListNode *next = NULL, *prev = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;
        ListNode *list1 = head;
        list2 = reverse(list2);
        while(list1 and list2){
            // cout<<list1->val <<" - " <<list2->val<<endl;
            if(list1->val != list2->val) return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        cout<<endl;
        if((list1 and list1->next)) return false;
        
        return true;
        
    }
};