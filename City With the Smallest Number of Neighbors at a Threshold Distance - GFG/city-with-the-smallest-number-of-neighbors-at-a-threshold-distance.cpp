//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int th) {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        for(auto i: edges){
            matrix[i[0]][i[1]] = i[2];
            matrix[i[1]][i[0]] = i[2];
        }
        for(int i=0; i<n; i++) matrix[i][i] = 0;
        
        for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(matrix[i][k] != INT_MAX and matrix[k][j] != INT_MAX){
	                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	                }
	            }
	        }
	    }
        int mn = INT_MAX, node = 0;
        for(int i=0; i<n; i++){
            int c = 0;
            for(int j=0; j<n; j++){
                if(matrix[i][j] <= th) c++;
            }
            if(c <= mn){
                mn = c;
                node = i;
            }
        }
        return node;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends