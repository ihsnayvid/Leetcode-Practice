//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int x, int y, int n, int m, vector<vector<char>> &mat){
        if(x < 0 or x >=n or y < 0 or y >= m or mat[x][y] != 'O') return;
        mat[x][y] = '#';
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            dfs(nx, ny, n, m, mat);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0; i<n; i++){
            if(mat[i][0] == 'O') dfs(i, 0, n, m, mat);
            if(mat[i][m-1] == 'O') dfs(i, m-1, n, m, mat);
        }
        
        for(int j=0; j<m; j++){
            if(mat[0][j] == 'O') dfs(0, j, n, m, mat);
            if(mat[n-1][j] == 'O') dfs(n-1, j, n, m, mat);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == '#') mat[i][j] = 'O';
                else if(mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends