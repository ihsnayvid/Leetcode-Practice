class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for(auto i: nums){
            if(!(i&1)) sum += i;
        }        
        
        for(auto q: queries){
            int x = q[0], i = q[1];
            if(!(nums[i] & 1))
                sum -= nums[i];
            nums[i] += x;
            if(!(nums[i] & 1))
                sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};