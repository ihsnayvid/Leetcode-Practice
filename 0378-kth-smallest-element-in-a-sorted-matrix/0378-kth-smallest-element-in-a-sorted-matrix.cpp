class Solution {
public:
    
    int countLess(vector<vector<int>> &v, int n, int val){
        int i = 0, j = n-1, count = 0;
        while(i < n and j >= 0){
            if(v[i][j] > val) j--;
            else{
                count += j + 1;
                i++;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            int mid = low + (high - low) / 2;
            int count = countLess(matrix, n, mid);
            if(count < k) low = mid + 1;
            else high = mid;

        }
        return low;
    }
};