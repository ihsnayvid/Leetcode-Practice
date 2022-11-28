class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(auto i: matches){
            mp[i[1]]++;
            st.insert({i[0], i[1]});
        }
        
        vector<int> one, zero;
        for(auto i: st){
            if(mp.count(i) <= 0)
                zero.push_back(i);
            else if(mp[i] == 1)
                one.push_back(i);
        }
        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        return {zero, one};
    }
};