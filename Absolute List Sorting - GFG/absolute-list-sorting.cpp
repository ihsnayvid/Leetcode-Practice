//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
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

    Node* sortList(Node* head)
    {
        if(!head or !head->next) return head;
        Node* pdummy = new Node();
        Node* ndummy = new Node();
        Node* pos = new Node();
        Node* neg = new Node();
        pdummy = pos;
        ndummy = neg;
        Node* temp = head;
        while(temp){
            if(temp->data >= 0){
                pos->next = temp;
                pos = pos->next;
            }
            else{
                neg->next = temp;
                neg = neg->next;
            }
            temp = temp->next;
        }
        neg->next = NULL;
        pos->next = NULL;
        neg = reverse(ndummy->next);
        if(!neg) return pdummy->next;
        // return neg;
        ndummy->next->next = pdummy->next;
        return neg;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends