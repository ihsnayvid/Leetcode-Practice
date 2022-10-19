//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(vector<vector<int>> &adj, unordered_set<int> &st, int i, int n) {
        
        st.insert(i);   
        if(st.size() == n) return true;
        for(auto x : adj[i]) {
            
            if(!st.count(x) and dfs(adj, st, x, n))  return true;
        }
        st.erase(i);
        return false;
    }
    
    
    bool check(int n,int m,vector<vector<int>> edges)
    {
        vector<vector<int>> adj(n+1);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        unordered_set<int> st;
        for(int i = 1; i <= n; i++) {
            if(dfs(adj, st, i, n)) return true;
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends