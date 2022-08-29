class Solution {
public:
    
    
//     int solve(vector<int> &v, int idx, int n, int sum){
//         if(idx >= n){
//             return sum;
//         }
        
//         int s1 = solve(v, idx+2, n, sum + v[idx]);
//         int s2 = solve(v, idx+3, n, sum + v[idx]);
//         return max(s1,s2);
//     }
    
//     int rob(vector<int>& nums) {
//         int s1 = solve(nums,0,nums.size(), 0);
//         int s2 = solve(nums,1,nums.size(), 0);
//         return max(s1,s2);
//     }
    
    int rob(vector<int>& nums){
        
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i=n-2; i>=0; i--){
            int cell1 = (i+2 < n) ? nums[i+2] : 0;
            int cell2 = (i+3 < n) ? nums[i+3] : 0;
            
            nums[i] += max(cell1, cell2);
        }
        
        return max(nums[0], nums[1]);
    }
};