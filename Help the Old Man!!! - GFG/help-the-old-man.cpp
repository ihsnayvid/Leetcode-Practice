// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> ans;
    void toh(int N, int &n, int a, int c, int b){
        if(n == 0 or N == 0) return;
        
        if(N == 1){
            n--;
            if(n == 0){
                ans.push_back(a);
                ans.push_back(c);
            }
            return;
        }
        
        toh(N-1, n, a, b, c);
        toh(1, n, a, c, b);
        toh(N-1, n, b, c, a);
        
    }
    vector<int> shiftPile(int N, int n){
        toh(N, n, 1, 3, 2);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends