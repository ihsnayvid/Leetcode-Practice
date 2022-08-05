class Solution {
public:
     
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        int vis[r][c];
        memset(vis,0,sizeof(vis));
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    int temp = 1;
                    int dx[4] = {0,0,1,-1};
                    int dy[4] = {1,-1,0,0};
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int i=0; i<4; i++){
                            int nextx = x + dx[i];
                            int nexty = y + dy[i];
                            if(nextx < 0 or nextx >=r or nexty < 0 or nexty >=c) continue;
                            if(grid[nextx][nexty] == 1 and !vis[nextx][nexty]){
                                temp ++;
                                q.push({nextx, nexty});
                                vis[nextx][nexty] = 1;
                            }
                        }
                        
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;    
    }
};