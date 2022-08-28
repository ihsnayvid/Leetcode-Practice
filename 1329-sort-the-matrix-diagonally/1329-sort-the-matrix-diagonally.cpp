class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int n = mat.size(), m = mat[0].size(), i, x, y, c;
        for(int j=0; j<m; j++){
            if(j == 0) i = n-1;
            else i = 0;
            for(; i>=0; i--){
                x = i, y = j;
                vector<int> v;
                while(x < n and y < m){
                    v.push_back(mat[x][y]);
                    x++, y++;
                }
                sort(v.begin(), v.end());                
                x = i, y = j, c = 0;
                while(x<n and y<m){
                    mat[x][y] = v[c++];
                    x++, y++;
                }
            }
        }
        return mat;
    }
};