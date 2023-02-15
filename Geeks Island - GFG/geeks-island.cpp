//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    void dfs(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &vis){
        vis[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx >= mat.size() or ny >= mat[0].size() or vis[nx][ny] or mat[nx][ny] < mat[x][y]) continue;
            dfs(nx, ny, mat, vis);
        }
    }
    
    int water_flow(vector<vector<int>> &mat,int n,int m){
        int ans = 0;
        vector<vector<int>> indian(n, vector<int> (m, 0)), arabian(indian);
        
        for(int i=0; i<n; i++){
            dfs(i, 0, mat, indian);
            dfs(i, m-1, mat, arabian);
        }
        
        for(int j=0; j<m; j++){
            dfs(0, j, mat, indian);
            dfs(n-1, j, mat, arabian);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(indian[i][j] and arabian[i][j]) ans++;
            }
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
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends