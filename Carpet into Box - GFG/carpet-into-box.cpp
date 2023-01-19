//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int a, int b){
        int count = 0;
        while(a > b){
            count++;
            a >>= 1;
        }
        return count;
    }
    
    int carpetBox(int a, int b, int c, int d){
        return min(solve(a, c) + solve(b, d), solve(a, d) + solve(b, c));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends