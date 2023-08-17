//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    // int solve(int i, int j, int wt[], int val[]){
    //     if(j == 0 or i == 0) return 0;
        
    //     int pick = INT_MIN, notPick = INT_MIN;
        
    //     notPick = solve(i-1, j, wt, val);
    //     if(j-wt[i-1] >= 0) pick = val[i-1] + solve(i-1, j-wt[i-1], wt, val);
        
    //     return max(pick, notPick);
    
    // }
    // //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                int pick = INT_MIN, notPick = INT_MIN;
        
                notPick = dp[i-1][j];
                if(j-wt[i-1] >= 0) pick = val[i-1] + dp[i-1][j-wt[i-1]];
                
                dp[i][j] = max(pick, notPick);
            }
        }
        return dp[n][W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends