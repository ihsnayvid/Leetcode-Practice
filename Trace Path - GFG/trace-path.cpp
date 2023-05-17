//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int x = 0, y = 0, minx = 0, miny = 0, maxx = 0 , maxy = 0;
        for(auto &i: s){
            if(i == 'L') y--;
            else if(i == 'R') y++;
            else if(i == 'D') x--;
            else x++;
            
            maxx = max(x, maxx);
            minx = min(x, minx);
            
            maxy = max(y, maxy);
            miny = min(y, miny);
        }
        
        return (maxx - minx < n) and (maxy - miny < m);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends