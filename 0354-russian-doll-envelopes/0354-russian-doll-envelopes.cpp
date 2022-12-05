class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), cmp);
        vector<int> v;
        for(auto i: env){
            auto it = lower_bound(v.begin(), v.end(), i[1]);
            if(it == v.end()) v.push_back(i[1]);
            else *it = i[1];            
        }
        return v.size();
    }
};