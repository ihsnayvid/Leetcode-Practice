//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i, int wt, int *price, vector<vector<int>> &dp){
        if(i == 0)
            return wt * price[0];
        if(dp[i][wt] != -1) return dp[i][wt];
        
        int pick = INT_MIN, notPick = INT_MIN;
        if(i+1 <= wt) pick = price[i] + solve(i, wt - i - 1, price, dp);
        notPick = solve(i-1, wt, price, dp);
        
        return dp[i][wt] = max(pick, notPick);
    }
  
    int cutRod(int price[], int n) {
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int wt = 0; wt <=n; wt++) prev[wt] = wt * price[0];
        
        for(int i=1; i<n; i++){
            for(int wt = 0; wt <= n; wt++){
                int pick = INT_MIN, notPick = INT_MIN;
                if(i+1 <= wt) pick = price[i] + curr[wt - i - 1];
                notPick = prev[wt];
                
                curr[wt] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends