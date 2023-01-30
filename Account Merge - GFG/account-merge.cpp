//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    vector<int> rank, size, parent;
    public:

    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pv == pu) return;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pv == pu) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution{
  public:
    unordered_map<string, int> mp;
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        
        for(int i=0; i<n; i++){
            for(int j=1; j<details[i].size(); j++){
                string s = details[i][j];
                if(mp.count(s) > 0)
                    ds.UnionBySize(i, mp[s]);
                else mp[s] = i;
            }
        }
        
        vector<vector<string>> ans(n);
        
        for(auto i: mp){
            string mail = i.first;
            int node = ds.findUPar(i.second);
            ans[node].push_back(mail);
        }
        
        vector<vector<string>> merged;
        for(int i=0; i<n; i++){
            if(ans[i].size() == 0) continue;
            sort(ans[i].begin(), ans[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it: ans[i]) temp.push_back(it);
            merged.push_back(temp);
        }
        sort(merged.begin(), merged.end(), greater<vector<string>>());
        return merged;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends