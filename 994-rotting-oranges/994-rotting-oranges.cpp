class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int total = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0) total ++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int count = 0, mins = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            int k = q.size();
            count += k;
            while(k--){
                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nextx = x + dx[i], nexty = y + dy[i];
                    if(nextx < 0 or nextx >= m or nexty < 0 or nexty >= n or grid[nextx][nexty] != 1) continue;           
                    grid[nextx][nexty] = 2;
                    q.push({nextx,nexty});
                }
            }
            if(!q.empty()) mins++;
        }
        if(count == total) return mins;
        else return -1;
    }
};