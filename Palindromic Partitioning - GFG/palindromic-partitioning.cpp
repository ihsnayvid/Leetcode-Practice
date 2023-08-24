//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501];
    bool isPal(string &s){
        for(int i=0, j = s.length()-1; i<j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    int solve(int i, string &str, int n){
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        string pre = "";
        for(int j=i; j<n; j++){
            pre += str[j];
            if(isPal(pre)){
                ans = min(ans, 1 + solve(j+1, str, n));
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, str, str.length())-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends