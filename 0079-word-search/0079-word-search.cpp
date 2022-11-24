class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool dfs(int idx, int i, int j, int n, int m, vector<vector<char>> &board, string &word){
        if(i<0 or j<0 or i>n or j>m or board[i][j] != word[idx]) return false;
        if(idx == word.size()-1) return true;
        board[i][j] = '.';
        for(int k=0; k<4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(dfs(idx+1, nx, ny, n, m, board, word)) return true;
        }
        board[i][j] = word[idx];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(0, i, j, n-1, m-1, board, word)) return true;
            }
        }
        return false;
    }
};