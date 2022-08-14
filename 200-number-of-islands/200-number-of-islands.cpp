class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans ++;
                    int dx[4] = {0,0,1,-1};
                    int dy[4] = {1,-1,0,0};
                    while(!q.empty()){
                        // ans++;
                        for(int i=0; i<q.size(); i++){
                            auto x = q.front().first;
                            auto y = q.front().second;
                            q.pop();
                            for(int k=0; k<4; k++){
                                int nextx = x + dx[k], nexty = y + dy[k];
                                if(nextx < 0 or nextx >= n or nexty < 0 or nexty >= m or grid[nextx][nexty] == '0')
                                    continue;
                                if(grid[nextx][nexty] == '1' and !vis[nextx][nexty]){
                                    vis[nextx][nexty] = 1;
                                    q.push({nextx,nexty});
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