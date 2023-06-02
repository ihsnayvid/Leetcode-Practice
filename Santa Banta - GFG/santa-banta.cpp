//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    const int size = 1000002;
    int isprime[1000002];
    vector<int> primes;
    void precompute(){
        memset(isprime, 1, sizeof(isprime));
        isprime[0] = 0;
        isprime[1] = 0;
        
        for(int i=2; i<=sqrt(size); i++){
            if(isprime[i]){
                for(int j=i*i; j<=size; j+=i)
                    isprime[j] = 0;
            }
        }
        for(int i=2; i<=size; i++){
            if(isprime[i]) primes.push_back(i);
        }
    }
    
    int dfs(int i, vector<int> &vis, vector<vector<int>> &adj){
        vis[i] = 1;
        int count = 1;
        for(auto &j: adj[i]){
            if(!vis[j]){
                count += dfs(j, vis, adj);
            }
        }
        return count;
    }
    int helpSanta(int n, int m, vector<vector<int>> &adj){
        
        vector<int> vis(n+1, 0);
        int k = 0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                k = max(k, dfs(i, vis, adj));
            }
        }
        // cout<<"k->"<<k<<"\n";
        if(k == 0 or m == 0) return -1;
        return primes[k-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends