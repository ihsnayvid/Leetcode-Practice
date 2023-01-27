//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    int n = s.length();
		    int mod = 1e9+7;
		    vector<int> dp(n+1, 0);
		    dp[0] = 1, dp[1] = 1;
		    
		    for(int i=2; i<=n; i++){
		        int num = stoi(s.substr(i-2, 2));
		        if(s[i-1] >= '1') dp[i] = (dp[i] + dp[i-1]) % mod;
		        if(num >= 10 and num <= 26) dp[i] = (dp[i] + dp[i-2]) % mod;
		    }
		    return dp[n] % mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends