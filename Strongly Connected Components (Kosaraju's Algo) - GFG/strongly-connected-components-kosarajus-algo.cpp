//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
    void dfs(int node, vector<int> &vis, vector<vector<int>>& adj, stack<int> &st){
        vis[node] = 1;
        for(auto &i: adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto &i: adj[node]){
            if(!vis[i]){
                dfs2(i, vis, adj);
            }
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vector<int> vis(n, 0);
        stack<int> st;
        
        //dfs and store the nodes in ascending order of finishing time
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        //reverse the edges
        vector<vector<int>> adj2(n);
        for(int i=0; i<n; i++){
            vis[i] = 0;
            for(auto &j: adj[i])
                adj2[j].push_back(i);
        }
        
        //dfs again
        int count = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                // cout<<"here"<<"\n";
                count++;
                dfs2(node, vis, adj2);
            }
        }
        return count;
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