//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int dp[1001][1001];
    int solve(int i, int j, string &s1, string &s2){
        if(i < 0 or j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s1[i] == s2[j]) ans =  1 + solve(i-1, j-1, s1, s2);
        else ans = max(solve(i-1, j, s1, s2), solve(i, j-1, s1, s2));
        
        return dp[i][j] = ans;
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n-1, m-1, s1, s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends