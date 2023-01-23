//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node* a, Node* b){
        if(!b) return a;
        if(!a) return b;
        
        Node* temp = new Node(-1);
        Node* dummy = temp;
        while(a and b){
            if(a->data <= b->data){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        
        if(a){
            temp->next = a;
            a = a->next;
        }
        
        if(b){
            temp->next = b;
            b = b->next;
        }
        
        return dummy->next;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(!head or !head->next) return head;
        
        Node* slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* first = head;
        Node* second = slow->next;
        slow->next = NULL;
        
        first = mergeSort(first);
        second = mergeSort(second);
        
        return merge(first, second);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends