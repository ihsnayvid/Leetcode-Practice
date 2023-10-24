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
        int st = 0, en = s.size()-1;
        while(st < en){
            if(s[st] != s[en]) return false;
            st++, en--;
        }
        return true;
    }
    int solve(int i, string &s){
        if(i >= s.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        string pre = "";
        int ans = INT_MAX;
        for(int j=i; j<s.size(); j++){
            pre += s[j];
            if(isPal(pre)){
                ans = min(ans, 1 + solve(j+1, s));
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, str) - 1;
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