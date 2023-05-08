//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        int modulo(string s,int m)
        {
            long long x = 1, k = 0;
            for(int i = s.size()-1; i>=0; i--){
                if(s[i] == '1') k += x;
                k %= m;
                x <<= 1;
                x %= m;
            }
            return k % m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends