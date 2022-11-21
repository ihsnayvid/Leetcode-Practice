class Solution {
public:
    bool border(int x, int y, int n, int m){
        return (x == 0 or x == n-1 or y == 0 or y == m-1);
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& st) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({st[0], st[1]});
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [x, y] = q.front();
                q.pop();
                // cout<<x<<","<<y<<endl;
                if(border(x, y, n, m) and (x != st[0] or y != st[1])) return steps;
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or maze[nx][ny] == '+') continue;
                    maze[nx][ny] = '+';
                    q.push({nx, ny});
                }
            }
            steps ++;
        }
        // cout<<steps<<"\n";
        return -1;
    }
};