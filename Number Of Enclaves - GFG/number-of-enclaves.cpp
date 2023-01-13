//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int x, int y, int n, int m, vector<vector<int>> &grid){
        if(x < 0 or y < 0 or x >= n or y >= m or grid[x][y] != 1) return;
        grid[x][y] = 2;
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            dfs(nx, ny, n, m, grid);
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) dfs(i, 0, n, m, grid);
            if(grid[i][m-1] == 1) dfs(i, m-1, n, m, grid);
        }
        
        for(int j=1; j<m-1; j++){
            if(grid[0][j] == 1) dfs(0, j, n, m, grid);
            if(grid[n-1][j] == 1) dfs(n-1, j, n, m, grid);
        }
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) ans ++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends