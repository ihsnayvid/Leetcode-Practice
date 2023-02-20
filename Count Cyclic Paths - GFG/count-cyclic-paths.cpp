//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
/*
1 0
2 3
3 6
4 21
5 60
6 183
7 546
*/
    int countPaths(int n){
        int mod = 1e9+7;
        vector<int> dp(n+2, 0);
        dp[0] = 0, dp[1] = 3;
        
        
        long long diff = 3, sign = 1;
        for(int i = 2; i < n; i++){
            dp[i] = (dp[i-1] + diff) % mod;
            long long d = 3 * (diff + (sign * 2));
            // cout<<diff<<"->"<<d<<endl;
            diff = d % mod;
            sign = -sign;
        }
        return dp[n-1] % mod;
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends