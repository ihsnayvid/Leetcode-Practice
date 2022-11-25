//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        if(n == 1) return k;
        
        long long same = k, diff = k * (k-1);
        long long total = same + diff, mod = 1e9+7;
        
        for(int i=3; i<=n; i++){
            same = diff;
            diff = ((total % mod)* ((k-1) % mod)) % mod;
            total = ((same % mod) + (diff % mod)) % mod;
        }
        return total % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends