//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int solve(int i, int sum, int *arr, vector<vector<int>> &dp){
	    if(i < 0) return sum == 0;
	    if(dp[i][sum] != -1) return dp[i][sum];
	    
	    int pick = sum - arr[i] >= 0 ? solve(i-1, sum - arr[i], arr, dp) % mod: 0;
	    int notPick = solve(i-1, sum, arr, dp) % mod;
	    
	    return dp[i][sum] = (pick + notPick) % mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(n-1, sum, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends