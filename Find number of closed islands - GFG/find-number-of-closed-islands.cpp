//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int bfs(int st, int en, vector<vector<int>>& mat, vector<vector<int>>& vis, int n, int m){
        queue<pair<int, int>> q;
        q.push({st, en});
        vis[st][en] = 1;
        int flag = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(mat[nx][ny] and !vis[nx][ny]){
                    if(nx == 0 or nx == n-1 or ny == 0 or ny == m-1) flag = 0;
                    else{
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return flag;
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(mat[i][j] and !vis[i][j])
                    ans += bfs(i, j, mat, vis, n, m);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends