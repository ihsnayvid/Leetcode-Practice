//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string ans = "";
    
    void topo(vector<int> adj[], int n){
        queue<int> q;
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i])
                indegree[it]++;
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans += (char)(node + 'a');
            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
    }
    
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        for(int s=0; s<n-1; s++){
            string s1 = dict[s], s2 = dict[s+1];
            for(int i=0; i<min(s1.length(), s2.length()); i++){
                if(s1[i] != s2[i]){
                    adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }
        }
        
        topo(adj, k);
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends