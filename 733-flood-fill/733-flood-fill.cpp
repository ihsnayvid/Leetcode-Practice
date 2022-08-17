class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        if(image[sr][sc] == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int start = image[sr][sc];
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [x,y] = q.front();
                q.pop();
                image[x][y] = color;
                for(int i=0; i<4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    
                    if(nx < 0 or nx >= m or ny < 0 or ny >= n or image[nx][ny] != start) continue;
                    q.push({nx,ny});                    
                }
            }
        }
        return image;
    }
};