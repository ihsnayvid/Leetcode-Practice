class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, prev = 0, mod = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            sum = sum + nums[i];
            mod = sum % k;
            if(st.count(mod)) return true;
            st.insert(prev);
            prev = mod;
        }
        return false;
    }
};