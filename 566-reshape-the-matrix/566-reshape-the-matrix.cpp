class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>ans(r,vector<int>(c));
        
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        
        vector<int> arr;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                arr.push_back(mat[i][j]);
        
        int k=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j] = arr[k++];
            }
        }
        
        return ans;
    }
};