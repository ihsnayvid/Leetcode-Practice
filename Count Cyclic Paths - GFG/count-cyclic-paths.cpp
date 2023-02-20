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
        long long ans = 0;
        for(int i=1; i<n; i++){
            ans = (ans * 3) % mod;
            if(i & 1) ans = (ans + 3) % mod;
            else ans = (ans - 3) % mod;
        }
        return ans % mod;
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