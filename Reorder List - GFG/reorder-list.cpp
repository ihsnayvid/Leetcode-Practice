//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:

    Node* reverse(Node* head){
        Node* curr = head, *next = NULL, *prev = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    // int count(Node* head){
    //     int n = 0;
    //     Node* t = head;
    //     while(t){
    //         n ++, t = t->next;
    //     }
    // }
    
    void reorderList(Node* head) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* second = slow->next;
        slow->next = NULL;
        second = reverse(second);
        
        Node* t1 = head, *t2 = second;
        // cout<<t1->data<<" "<<t2->data<<endl;
        Node* list = new Node(0);
        Node* temp = list;
        list->next = t1;
        
        while(t1){
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
            temp->next = t2;
            if(t2){
                t2 = t2->next;
                temp = temp->next;
            }
        }
    
    }
    
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends