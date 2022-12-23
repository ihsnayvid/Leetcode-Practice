//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    int solve(int st, int en, vector<int> &v, vector<vector<int>> &dp){
        if(st > en) return 0;
        if(dp[st][en] != -1) return dp[st][en];
        int ans = INT_MIN;
        for(int i=st; i<=en; i++){
            int val = v[st-1] * v[i] * v[en+1] + solve(st, i-1, v, dp) + solve(i+1, en, v, dp);
            ans = max(ans, val);
        }
        return dp[st][en] = ans;
    }
    
    int maxCoins(int n, vector<int> &arr) {
        vector<int> v(n+2, 1);
        for(int i=0; i<n; i++)
            v[i+1] = arr[i];
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        
        return solve(1, n, v, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends