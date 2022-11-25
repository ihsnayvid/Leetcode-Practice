//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    long long nCr(long long n, long long r){
        if(r == 0) return 1;
        long long v[r+1] = {0};
        
        v[0] = 1;
        for(long long i=1; i<=n; i++){
            for(long long j=r; j>0; j--)
                v[j] = v[j] + v[j-1];
        }
        return v[r];
    }
    
    long long count(long long x) {
        long long r = 0, setBits = 0;
        
        for(int i = 0; i < 64; i++){
            if(x & 1){
                setBits++;
                long long comb = nCr(i, setBits);
                r += comb;
            }
            x = x >> 1;
        }
        
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends