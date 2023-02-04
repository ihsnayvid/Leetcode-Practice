//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int solve(int idx, int n, int arr[], vector<int> &dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int pick = arr[idx] + solve(idx + 2, n, arr, dp);
        int notpick = solve(idx + 1, n, arr, dp);
        
        return dp[idx] = max(pick, notpick);
        
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    return max(solve(0, n, arr, dp), solve(1, n, arr, dp));
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends