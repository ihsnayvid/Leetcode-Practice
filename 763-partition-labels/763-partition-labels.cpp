class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++)
            mp[s[i]] = i;
        
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            //cout<<s[i]<<" ";
            int r = mp[s[i]];
            int curr = r;
            for(int j=i; j<curr; j++){
                if(mp[s[j]] > curr)
                    curr = mp[s[j]];
            }
            ans.push_back(curr - i + 1);
            i = curr;
            //cout<<i<<"--";
        }
        return ans;
    }
};