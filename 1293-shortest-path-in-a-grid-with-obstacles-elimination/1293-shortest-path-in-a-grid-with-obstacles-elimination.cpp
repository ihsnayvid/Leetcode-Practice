class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
        queue<vector<int>> q;
        
        //x, y curr path, rem k
        q.push({0,0,0,k});
        while(!q.empty()){
            auto curr = q.front();
            int x = curr[0];
            int y = curr[1];
            q.pop();
            
            if(x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size())
                continue;
		    if(x == grid.size()-1 and y == grid[0].size()-1)
                return curr[2];
            
            if(grid[x][y]){
                if(curr[3]>0)
                    curr[3]--;
                else
                    continue;
            }
            
            if(vis[x][y]!=-1 and vis[x][y] >= curr[3])
                continue;
            vis[x][y] = curr[3];
             
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                q.push({nx, ny, curr[2] + 1, curr[3]});
            }
        }
        return -1;
    }
};