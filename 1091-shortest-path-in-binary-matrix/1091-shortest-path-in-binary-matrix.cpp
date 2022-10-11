class Solution {
public:
    int dx[8] = {0,0,1,-1,-1,1,1,-1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0 or grid[n-1][m-1] != 0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            auto [x, y] = q.front();
            if(x == n-1 and y == m-1) return grid[x][y];
            q.pop();
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 or ny<0 or nx>=n or ny>=m or grid[nx][ny] != 0) continue;
                q.push({nx, ny});
                grid[nx][ny] = grid[x][y] + 1;
            }
        }
        return -1;
    }
};