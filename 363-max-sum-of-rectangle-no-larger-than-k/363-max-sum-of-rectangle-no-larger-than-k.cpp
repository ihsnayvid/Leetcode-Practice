class Solution {
public:
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size(), n = matrix[0].size(), mx = INT_MIN, curr = 0;
        
        for(int i=0; i<n; i++){
            vector<int> sum(m,0);
            for(int j=i; j<n; j++){
                for(int x=0; x<m; x++)
                    sum[x] += matrix[x][j];
                
                int curr = 0, currMax = INT_MIN;
                set<int> st;
                st.insert(0);
                
                for(auto s: sum){
                    curr += s;
                    auto it = st.lower_bound(curr - k);
                    if(it != st.end()) currMax = max(currMax, curr - *it);
                    st.insert(curr);
                }
                mx = max(mx, currMax);
            }
        }
        if(mx == INT_MIN) return -1;
        return mx;
        
    }
};