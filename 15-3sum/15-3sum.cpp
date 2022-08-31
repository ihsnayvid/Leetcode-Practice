class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int x = nums[i];
            int st = i+1, en = n-1;
            while(st < en){
                if(nums[i] + nums[st] + nums[en] == 0) {
                    s.insert({nums[i],nums[st],nums[en]});
                    st++, en --;
                }
                else if(nums[i] + nums[st] + nums[en] < 0) st++;
                else en--;
            }
        }
        for(auto i: s)
            ans.push_back(i);
        return ans;
    }
};