// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        if(x == y) return 0;
        int mn = min(x,y), mx = max(x,y), count = 0;
        
        while(mx != mn){
            mx >>= 1;
            count++;
            
            if(mx < mn) swap(mx,mn);
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends