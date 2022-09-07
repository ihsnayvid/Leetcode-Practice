class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // vector<string> s = strs;    //copy of strs
        unordered_map<string, vector<string>> mp;
        
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            mp[word].push_back(strs[i]);
        }
        
        for(auto i: mp)
            ans.push_back(i.second);
        
        return ans;
    }
};