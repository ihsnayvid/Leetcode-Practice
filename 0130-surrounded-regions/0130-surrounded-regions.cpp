class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        if(i<0 or i>=n  or j<0 or j>=m )return;
        if(board[i][j] != 'O')return;
        board[i][j] = '#';
        
        for(int k=0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            dfs(board, nx, ny, n, m);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        if(n == 0 or m == 0)return;
        for(int i=0; i<m ; i++){
            if(board[0][i] == 'O')   dfs(board, 0, i, n, m);
            if(board[n - 1][i] == 'O')    dfs(board, n-1, i, n, m);
        }
        for(int i=1; i<n-1; i++){
            if(board[i][0] == 'O')   dfs(board, i, 0, n, m);
            if(board[i][m - 1] == 'O')  dfs(board, i, m - 1, n, m);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] != '#')  board[i][j] = 'X';
                else  board[i][j] = 'O';
            }
        }
    }
    
};