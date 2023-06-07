//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isPrime[100001];
    void sieve(int n){
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[0] = 0;
        isPrime[1] = 1;
        for(int i=2; i<=sqrt(n); i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i)
                    isPrime[j] = 0;    
            }
        }
    }
    int lpf(int n){
        if(n == 1) return 1;
        if(isPrime[n]) return n;
        for(int i=2; i<=n; i++){
            if(isPrime[i] and n % i == 0) return i;
        }
        return n;
    }
    
    vector<int> leastPrimeFactor(int n) {
        sieve(n+1);
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++) ans[i] = lpf(i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends