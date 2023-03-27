//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int solve(int sum, int k, int num, int dp[101][101][101]){
        if(sum == 0 and k == 0) return 1;
        else if(sum == 0 or k == 0) return 0;
        if(dp[sum][k][num] != -1) return dp[sum][k][num];
        int ans = 0;
        for(int i=num; i<=sum; i++) ans += solve(sum - i, k - 1, i, dp);
        return dp[sum][k][num] = ans;
    }
  
    int countWaystoDivide(int n, int k) {
        int dp[101][101][101];
        memset(dp, -1, sizeof(dp));
        return solve(n, k, 1, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends