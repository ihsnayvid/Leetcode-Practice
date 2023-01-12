//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    // int bfs(vector<vector<int>> &grid, int n, int m, int x, int y){
    //     vector<vector<int>> vis(n, vector<int>(m, 0));
    //     queue<pair<int, int>> q;
    //     q.push({x, y});
    //     vis[x][y] = 1;
    //     int dist = 0;
    //     while(!q.empty()){
    //         int s = q.size();
    //         while(s--){
    //             auto curr = q.front();
    //             q.pop();
    //             int x = curr.first, y = curr.second;
                
    //             if(grid[x][y] == 1) return dist;
                
    //             for(int i=0; i<4; i++){
    //                 int nx = x + dx[i], ny = y + dy[i];
    //                 if(nx < 0 or ny < 0 or nx >=n or ny >= m or vis[x][y]) continue;
    //                 q.push({nx, ny});
    //                 vis[nx][ny] = 1;
    //             }
                
    //         }
    //         dist++;
    //     }
    //     return 0;
    // }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	   // vector<vector<int>> ans(n, vector<int>(m, -1));
	    queue<pair<int, int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                grid[i][j] = 0; 
	                q.push({i, j});
	            }
	            else grid[i][j] = -1;
	        }
	    }
	    
	    while(!q.empty()){
	        auto curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 or ny < 0 or nx >=n or ny >= m or grid[nx][ny] != -1) continue;
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
	    }
	    
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends