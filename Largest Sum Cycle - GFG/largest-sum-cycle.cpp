//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
    
    long long dfs(int i, int p, vector<int> &edge, vector<int> &vis, vector<int> &pathvis){
        if(pathvis[i] or vis[i]){
            if(i == p) return 0;
            else return -1;
        }
        
        vis[i] = 1;
        pathvis[i] = 1;
        if(edge[i] == -1) return -1;
        long long sum = dfs(edge[i], p, edge, vis, pathvis);
        pathvis[i] = 0;
        
        if(sum == -1){
            vis[i] = 0;
            return -1;
        }
        else return sum + i;
        
    }  
    

  long long largestSumCycle(int n, vector<int> edge)
  {
        vector<int> vis(n+1, 0), pathvis(n+1, 0);
        long long ans = -1;
        for(int i=0; i<n; i++){
            if(!vis[i])
                ans = max(ans, dfs(i, i, edge, vis, pathvis));
        }
        return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends