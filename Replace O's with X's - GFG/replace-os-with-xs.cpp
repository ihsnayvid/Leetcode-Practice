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
    
    void dfs(int i, int j, vector<vector<char>> &mat, int n, int m){
        if(i < 0 or j < 0 or i >= n or j >= m or mat[i][j] != 'O') return;
        mat[i][j] = '*';
        for(int k=0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            dfs(nx, ny, mat, n, m);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0; i<n; i++){
            if(mat[i][0] == 'O') dfs(i, 0, mat, n, m);
            if(mat[i][m-1] == 'O') dfs(i, m-1, mat, n, m);
        }
        
        for(int j=0; j<m-1; j++){
            if(mat[0][j] == 'O') dfs(0, j, mat, n, m);
            if(mat[n-1][j] == 'O') dfs(n-1, j, mat, n, m);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != '*') mat[i][j] = 'X';
                else mat[i][j] = 'O';
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