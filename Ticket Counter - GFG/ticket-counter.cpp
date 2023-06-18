//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        deque<int> q;
        for(int i=1; i<=n; i++) q.push_back(i);
        
        while(q.size() > 1){
            int x = k;
            while(x-- and q.size() > 1) q.pop_front();
            
            x = k;
            while(x-- and q.size() > 1) q.pop_back();
        }
        return q.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends