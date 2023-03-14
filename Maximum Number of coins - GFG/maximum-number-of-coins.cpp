//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int solve(int st, int en, vector<int> &a, vector<vector<int>> &dp){
            if(st > en) return 0;
            if(dp[st][en] != -1) return dp[st][en];
            int ans = 0;
            for(int i=st; i<=en; i++){
                int curr = (a[st-1] * a[i] * a[en+1]) + solve(st, i-1, a, dp) + solve(i+1, en, a, dp);
                ans = max(ans, curr);
            }
            return dp[st][en] = ans;
        }
        
        int maxCoins(int n, vector <int> &a)
        {
            a.insert(a.begin(), 1);
            a.push_back(1);
            vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
            return solve(1, n, a, dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends