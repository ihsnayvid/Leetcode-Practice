//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pi;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<int> vis(n, 0);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(vis[u]) continue;
            vis[u] = 1;
            sum += d;
            for(auto i: adj[u]){
                int v = i[0], wt = i[1];
                if(!vis[v]) pq.push({wt, v});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends