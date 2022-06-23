// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	    if(n == 1) return 4;
	    long mod = 1000000007;
	    vector<int> ans(n+1,0);
	    ans[1] = 2;
	    ans[2] = 3;
	    for(int i=3; i<=n; i++)
	        ans[i] = ((ans[i-1] % mod) + (ans[i-2] % mod)) % mod;
	        
	    return ((ans[n] % mod ) * (ans[n] % mod)) % mod;
	    //return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends