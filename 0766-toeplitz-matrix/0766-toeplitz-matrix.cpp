class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        //for entire first row
        for(int j=0, i=0; j<m; j++){
            int x = i, y = j;
            int val = matrix[i][j];
            while(x < n and y < m){
                if(matrix[x++][y++] != val) return false;
            }
        }
        
        //for entire first column
        for(int i=1, j=0; i<n; i++){
            int x = i, y = j;
            int val = matrix[i][j];
            while(x < n and y < m){
                if(matrix[x++][y++] != val) return false;
            }
        }
        return true;
    }
};