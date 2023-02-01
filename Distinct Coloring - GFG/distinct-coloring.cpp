//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        vector<vector<long long>> dp(n+1, vector<long long>(3, 0));
        dp[0][0] = r[0], dp[0][1] = g[0], dp[0][2] = b[0];
        
        for(int i=1; i<n; i++){
            dp[i][0] = r[i] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = g[i] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = b[i] + min(dp[i-1][0], dp[i-1][1]);
        }
        
        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends