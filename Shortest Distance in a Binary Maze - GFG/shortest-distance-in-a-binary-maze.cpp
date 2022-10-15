//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int ans = 0;
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        int s1 = source.first, s2 = source.second, d1 = destination.first, d2 = destination.second;
        if(grid[s1][s2] == 0 or grid[d1][d2] == 0) return -1;
        queue<pair<int,int>> q;
        q.push({s1, s2});
        grid[s1][s2] = 0;
        while(!q.empty()){
            auto x = q.front().first, y = q.front().second;
            q.pop();
            if(x == d1 and y == d2) return grid[x][y];
            for(int i=0; i<4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx < 0 or ny < 0 or nx >= n or ny >= m or grid[nx][ny] != 1 ) continue;
                
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends