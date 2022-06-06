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
        int ca=0,cb=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA){
            ca++;
            tempA=tempA->next;
        }
        
        while(tempB){
            cb++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(cb>ca){
            cb=cb-ca;
            while(cb--) tempB=tempB->next; 
        }
        else{
            ca=ca-cb;
            while(ca--) tempA=tempA->next; 
        }
        while(tempA and tempB){
            if(tempA == tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};