class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 < n2)
            swap(nums1,nums2);
        
        for(auto i: nums1) mp[i]++;          
       // for(auto x: mp) cout<<x.first<<"->"<<x.second<<"\n";        
        for(auto i: nums2){
            if(mp[i] > 0){                
                ans.push_back(i);
                mp[i]--;
            }
        }
        
        return ans;
    }
};