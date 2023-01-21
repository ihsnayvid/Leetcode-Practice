//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  
    struct cmp{        
        bool operator() (Node* a, Node* b){
            return a->data > b->data;
        }
    };
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        Node* dummy = new Node(-1);
        Node* pre = dummy;

        for(int i=0; i<k; i++){
            if(arr[i] != NULL) pq.push(arr[i]);
        }

        while(!pq.empty()){
            Node *min = pq.top();
            pq.pop();
            pre->next = min;
            pre = min;
            if(min->next) pq.push(min->next);
        }

        return dummy->next;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends