//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    int countNodes(struct node *head){
        struct node *t = head;
        int c = 0;
        while(t)
            c++, t = t->next;
        return c;
    }
    
    struct node *rev(struct node *head){
        struct node *curr = head, *prev = NULL, *next = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        if(!head or k == 1) return head;
        struct node *dummy = new node(0);
        dummy->next = head;
        struct node *pre =  new node(0);
        pre = dummy;
        
        int count = countNodes(head);
        struct node *curr, *next;
        
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
    
        
        struct node * second = rev(next);
        curr->next = second;
        return dummy->next;
    }
    
    
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends