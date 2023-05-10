//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
        int count = 0;
        vector<int> large(n, a[0]);
        for(int i=1; i<n; i++)
            large[i] = max(a[i], large[i-1]);
        
        vector<int> small(n, a[n-1]);
        for(int i = n-2; i>=0; i--)
            small[i] = min(a[i], small[i+1]);
            
        
        for(int i=0; i<n-1; i++){
            if((large[i] + small[i+1]) >= k) count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends