class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++)
            mp[s[i]] = i;
        
        vector<int> ans;
        int last = -1, mx = INT_MIN;            

        for(int i=0; i<s.size(); i++){
            mx = max(mx, mp[s[i]]);
            if(mx == i){
                ans.push_back(i - last);
                last = i;
            }
        }
        return ans;
    }
};