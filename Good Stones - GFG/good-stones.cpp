//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool dfs(int node, vector<int> &arr, vector<int> &vis, vector<int> &pathvis, vector<int> &check){
        vis[node] = 1;
        pathvis[node] = 1;
        int i = node + arr[node];
        if(i >= 0 and i < arr.size()){
            if(!vis[i]){
                if(dfs(i, arr, vis, pathvis, check)) return true;
            }
            else if(pathvis[i]) return true;
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    
    int goodStones(int n,vector<int> &arr){
        vector<int> vis(n+1, 0), pathvis(vis), check(vis);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, arr, vis, pathvis, check);
        }
        for(int i=0; i<n; i++){
            if(check[i]) count++;
        }
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends