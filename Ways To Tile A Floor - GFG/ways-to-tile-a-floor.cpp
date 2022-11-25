//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    const int mod = 1e9+7;
    long long solve(long long n, vector<long long> &dp){
        if(n == 1 or n == 2) return n;
        if(dp[n] != -1) return dp[n] % mod;
        return dp[n] = ((solve(n-1, dp) % mod) + (solve(n-2, dp) % mod)) % mod;
    }
    long long numberOfWays(long long n) {
        vector<long long> dp(n+1, -1);
        return solve(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends