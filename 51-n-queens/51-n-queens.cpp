class Solution {
public:
    vector<vector<string>> ans;
    
    bool check(vector<string> board, int row,int col){
        for(int i=0; i<=row; i++){
            if(board[i][col] == 'Q') return false;
            if(row-i >=0 and col-i >=0 and board[row-i][col-i] == 'Q') return false;
            if(row-i >=0 and col+i >=0 and board[row-i][col+i] == 'Q') return false;
        }
        
        return true;
    }
    
    void solve(int row, vector<string> &board){
        if(board.size() == row){
            ans.push_back(board);
            return;
        }
        
        for(int col=0; col<board.size(); col++){
            if(check(board,row,col)){
                board[row][col] = 'Q';
                solve(row+1, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(0,board);
        return ans;
    }
};