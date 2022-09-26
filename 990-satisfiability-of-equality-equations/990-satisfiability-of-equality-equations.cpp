
class Solution {
public:
    unordered_map<char, vector<char>> adj; // The graph
    vector<bool> initial; // initial vis.
    vector<bool> vis; // current vis

    void dfs(char src){ 
        if(vis[src]) return;
        vis[src] = true;

        for(char c: adj[src]) dfs(c);
    }

    bool equationsPossible(vector<string>& arr) {
        
        initial.resize(256, false);
        vector<pair<char, char>> diff; // storing the pairs having different values
        
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i][1] == '='){  // adding bidirectional edge
                adj[arr[i][0]].push_back(arr[i][3]); 
                adj[arr[i][3]].push_back(arr[i][0]); 
            }else{
                if(arr[i][0] == arr[i][3]) return false;  // type a != a
                diff.push_back({arr[i][0], arr[i][3]});
            }
        }
        
        for(int i = 0; i<diff.size(); i++){
            char u = diff[i].first;
            char v = diff[i].second;
            vis = initial;
            dfs(u);  // running dfs from u
            if(vis[v]) return false; // if v becomes visited return false
        }
        
        return true;

    }
};