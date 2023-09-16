//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1e9+7;
    long long dp[100001];
    long long solve(int i){
        if(i < 0) return 0;
        if(i == 0) return 1;
        
        if(dp[i] != -1) return dp[i];
        long long ans = solve(i-1) % mod;
        ans = (ans + solve(i-2) % mod) % mod;
        ans = (ans + solve(i-3) % mod) % mod;
        return dp[i] = ans;
    }
    
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        if(n == 1) return 1;
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends