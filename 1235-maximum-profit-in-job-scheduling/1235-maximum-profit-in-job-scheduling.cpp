class Solution {
public:   
    
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = profit.size();
        vector<int> dp(n+1, 0);
        vector<vector<int>> v;
        for(int i=0; i<n; i++)
            v.push_back({st[i], et[i], profit[i]});
        sort(v.begin(), v.end());
        sort(st.begin(), st.end());
        
        for(int i=n-1; i>=0; i--){
            int idx = lower_bound(st.begin(), st.end(), v[i][1]) - st.begin();
            dp[i] = max(dp[i+1], dp[idx] + v[i][2]);
        }
        
        return dp[0];
    }
};