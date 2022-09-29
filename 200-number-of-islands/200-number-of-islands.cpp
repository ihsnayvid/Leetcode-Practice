class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    vis[i][j] = true;
                    q.push({i,j});
                    ans++; 
                        
                    while(!q.empty()){
                        int s = q.size(); 
                        while(s--){
                            auto [x, y] = q.front();
                            q.pop();
                            for(int k=0; k<4; k++){
                                int nx = x + dx[k], ny = y + dy[k];
                                if(nx >=0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == '1' and !vis[nx][ny]){
                                    vis[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }                        
                    }
                }
            }
        }
        return ans;
    }
};