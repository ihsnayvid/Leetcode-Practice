class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int j=0; j<m; j++){
            int st = 0, en = n-1;
            while(st<en){
                swap(matrix[st][j], matrix[en][j]);
                st++, en --;
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
   }
};