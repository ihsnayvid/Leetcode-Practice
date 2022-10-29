class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        
        vector<pair<int, int>> vp;
        for(int i=0; i<pt.size(); i++){
            vp.push_back({gt[i], pt[i]});
        }
        
        sort(vp.rbegin(), vp.rend());
        
        int ans = 0, sum = 0;
        for(auto i: vp){
            sum += i.second;
            ans = max(ans, sum + i.first);
        }
        return ans;
    }
};