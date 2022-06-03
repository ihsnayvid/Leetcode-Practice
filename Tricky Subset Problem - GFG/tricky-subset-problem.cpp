// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    //1  2  4  2   s=1 -> 3 -> 8
    //2  5  
    
    //x = 7 -> 2 -> 0 | i = 1 -> 0
    
    int isPossible(long long s, long long n, long long x, long long a[])
    {
        // vector<int> v;
        // v.push_back(s);
        long long tempS = s;
        int i;
        for(i=0; i<n; i++){
            a[i] += s;
            s += a[i];
            if(s > x) break;
        }
        
        if(s == x) return true;
        
        while(x >= 0 and i >= 0){
            if(x >= a[i]) x -= a[i];
            
            if(x == 0 or x-tempS == 0) return true;
            i--;
        }
        return false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends