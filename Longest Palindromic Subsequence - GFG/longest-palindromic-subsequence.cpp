//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(int i, int j, string &a, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(a[i] == a[j]) ans = 2 + solve(i+1, j-1, a, dp);
        else ans = max(solve(i+1, j, a, dp), solve(i, j-1, a, dp));
        
        return dp[i][j] = ans;
    }
    int longestPalinSubseq(string a) {
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, a, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends