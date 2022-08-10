class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i: nums)
            mp[i]++;
        
        for(int i=1; i<=nums.size(); i++){
            if(mp[i] < 1)
                ans.push_back(i);
        }
        
        return ans;
    }
};