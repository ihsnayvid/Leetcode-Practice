//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
    stack<int> st;
	
	void dfs(int node, vector<int> &vis, vector<vector<int>>& adj, int check){
	    vis[node] = 1;
	    for(auto i: adj[node]){
	        if(!vis[i]) dfs(i, vis, adj, check);
	    }
	    if(check) st.push(node);
	}
	
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vector<int> vis(n);
        int c = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i, vis, adj, 1);
        }
        
        vector<vector<int>> adj2(n);
        for(int i=0; i<n; i++){
            vis[i] = 0;
            for(auto j: adj[i]){
                adj2[j].push_back(i);
            }
        }
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                c++;
                dfs(node, vis, adj2, 0);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends