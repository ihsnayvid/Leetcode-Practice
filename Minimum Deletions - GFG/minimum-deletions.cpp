//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(int i, int j, string &s){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans;
        if(s[i] == s[j]) ans = solve(i+1, j-1, s);
        else ans = 1 + min(solve(i+1, j, s), solve(i, j-1, s));
        return dp[i][j] = ans;
    }
        
    int minimumNumberOfDeletions(string s) { 
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size()-1, s);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends