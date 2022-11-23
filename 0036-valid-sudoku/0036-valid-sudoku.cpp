class Solution {
public:
    bool check(vector<char> v){
        unordered_map<char,int> mp;
        for(auto i: v){
            if(i != '.'){
                if(mp.find(i) != mp.end()) return false;
                mp[i]++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //check row
        for(int i=0; i<9; i++)
            if(!check(board[i])) return false;
        
        //check column
        for(int j=0; j<9; j++){
            unordered_map<char, int> mp;
            for(int i=0; i<9; i++){
                if(board[i][j] != '.'){
                    if(mp.find(board[i][j]) != mp.end()) return false;
                    mp[board[i][j]]++;
                }
            }
        }    
        
        //check sub-boxes
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){                
                unordered_map<char, int> mp;                
                for(int k=0; k<9; k++){                
                    int row = 3*(i/3) + k/3;
                    int col = 3*(j/3) + k%3;
                    char num = board[row][col];
                    if(num != '.'){
                        if(mp.find(num) != mp.end()) return false;
                        mp[num]++;
                    }
                }                
            }
        }
        return true;
    }
};