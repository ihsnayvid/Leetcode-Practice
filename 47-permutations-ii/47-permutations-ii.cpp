class Solution {
public:
    vector<vector<int>> ans;
    //unordered_set<vector<int>> st;
    void solve(vector<int> nums, vector<int> temp){
        if(temp.size() == nums.size()){
            //st.insert(temp);
            ans.push_back(temp);
            return;
        }
        
       
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != -100){

                if(i > 0 and nums[i] == nums[i-1] and nums[i-1] != -100) continue;
                int k = nums[i];
                nums[i] = -100;
                temp.push_back(k);
                
                solve(nums,temp);
                
                temp.pop_back();
                nums[i] = k;
            }
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp);
        return ans;
    }
};