//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    // int solve(int i, int j, int *arr){
    //     if(i == j) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int mn = 1e9;
    //     for(int k=i; k<j; k++){
    //         int steps = arr[i-1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k+1, j, arr);
    //         mn = min(steps, mn);
    //     }
    //     return dp[i][j] = mn;
    // }
    int matrixMultiplication(int n, int arr[])
    {
        dp.resize(n, vector<int>(n, 0));
        
        for(int i=n-1; i > 0; i--){
            for(int j=i+1; j<n; j++){
                int mn = 1e9;
                for(int k=i; k<j; k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mn = min(steps, mn);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends