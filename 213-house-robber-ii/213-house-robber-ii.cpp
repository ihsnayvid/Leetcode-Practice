class Solution {
public:
    int solve(vector<int> &nums){
        
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        for(int i=n-2; i>=0; i--){
            int cell1 = (i+2 < n) ? nums[i+2] : 0;
            int cell2 = (i+3 < n) ? nums[i+3] : 0;
            
            nums[i] += max(cell1, cell2);
        }
        
        return max(nums[0], nums[1]);
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> b(nums.begin() + 1, nums.end());
//         for(auto i: a) cout<<i<<" ";
//         cout<<endl;
//         for(auto i: b) cout<<i<<" ";
//         cout<<endl;
        
        return max(solve(a), solve(b));
    }
};