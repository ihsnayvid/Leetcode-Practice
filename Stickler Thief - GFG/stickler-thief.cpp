//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> dp;
    int solve(int i, int *arr){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        
        int pick = arr[i] + solve(i-2, arr);
        int notPick = solve(i-1, arr);
        return dp[i] = max(pick, notPick);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        dp.resize(n+1, -1);
        return solve(n-1, arr);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends