//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'Y') q.push({i, j}), vis[i][j] = 1;
            }
        }
        
        int ans = INT_MAX, steps = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;
                if(grid[x][y] == 'X') return steps; 
                for(int i=0; i<4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends