//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public: 
    int dp[1001][1001];
    int solve(int i, int j, int *val, int *wt){
        if(j == 0) return 0;
        if(i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int pick = wt[i] <= j ? val[i] + solve(i, j-wt[i], val, wt) : 0;
        int notPick = solve(i-1, j, val, wt);
        
        return dp[i][j] = max(pick, notPick);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return solve(n-1, w, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends