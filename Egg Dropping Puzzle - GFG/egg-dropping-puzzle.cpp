//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int dp[301][301];
   
    int solve(int n,int k)
    {
       
       if(n == 1) return k;
       if(k == 0) return 0;
       
       if(dp[n][k] != -1) return dp[n][k];
       
       int ans = INT_MAX;
       for(int i=1; i<=k; i++){
           int broken = solve(n-1, i-1);
           int notBroken = solve(n,k-i);
           ans = min(ans, max(broken,notBroken) + 1);
       }
       
       return dp[n][k] = ans;
    }
   
    int eggDrop(int n, int k) {
       memset(dp, -1, sizeof(dp));
       return solve(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends