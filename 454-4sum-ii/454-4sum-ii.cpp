class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0, n = nums1.size();
        unordered_map<int,int> mp1, mp2;
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++)
                mp1[nums1[i] + nums2[j]]++;
        }
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++)
                mp2[nums3[i] + nums4[j]]++;
        }
        
        for(auto i: mp1){
            if(mp2.find(-i.first) != mp2.end())
                ans += i.second * mp2[-i.first];
        }
        
        return ans;
    }
};