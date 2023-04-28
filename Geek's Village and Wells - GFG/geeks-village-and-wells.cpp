//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int> (m, -1));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(c[i][j] == 'W'){
                    q.push({i, j});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
                else if(c[i][j] == 'N' or c[i][j] == '.') ans[i][j] = 0;
            }
        }
    
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(c[x][y] == 'H') ans[x][y] = steps * 2;
                
                for(int k=0; k<4; k++){
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny] or c[nx][ny] == 'N') continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            steps++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends