class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int i = 0, j = 0;
        
        string str = "";
        while(j<s.size()){
            str += s[j];
            if(j-i+1 == 10){
                mp[str]++;
                str.erase(0,1);
                i++;
            }
            j++;
        }
        
        vector<string> ans;
        for(auto i: mp){
            if(i.second > 1)
                ans.push_back(i.first);
        }
        
        return ans;
    }
};