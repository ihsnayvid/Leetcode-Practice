//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    int solve(int i, int p, vector<vector<int>> &v, vector<vector<int>> &dp){
        if(i == v.size() or p == 2) return 0;
        
        if(dp[i][p] != -1) return dp[i][p];
        
        int notPick = solve(i+1, p, v, dp);
        int pick = v[i][2];
        
        int low = i+1, high = v.size()-1, idx = v.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[i][1] <= v[mid][0]){
                idx = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        pick += solve(idx, p+1, v, dp);
        return dp[i][p] = max(pick, notPick);
    }
    int maxCoins(int n,vector<vector<int>> &v){
        vector<vector<int>> dp(v.size(), vector<int> (3, -1));
        sort(v.begin(), v.end());
        return solve(0, 0, v, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends