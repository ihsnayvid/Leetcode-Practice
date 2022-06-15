class Solution {
public:
    static bool cmp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), cmp);
        unordered_map<string,int> mp;
        
        int ans = INT_MIN;
        for(auto w: words){
            mp[w] = 1;
            for(int i=0; i<w.size(); i++){
                string s = w.substr(0,i) + w.substr(i+1);
                if(mp.find(s) != mp.end())
                    mp[w] = mp[s] + 1;
                ans = max(ans,mp[w]);                
            }
        }
        
        return ans;
    }
};