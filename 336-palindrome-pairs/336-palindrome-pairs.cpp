class Solution {
public:
    bool isPalindrome(string s){
        int st = 0, en = s.length()-1;
        while(st <= en){
            if(s[st] != s[en]) return false;
            st++, en --;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        if(n == 0) return ans;
        
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++){            
            string rev = words[i];
            reverse(rev.begin(), rev.end());            
            mp[rev] = i;
        }
        
        
        for(int i=0; i<n; i++){
            int l = words[i].length();
                
            string st = "", en = "";
            for(int j=0; j<l; j++){
                st += words[i][j];
                en = words[i].substr(j+1);
                 
                if(mp.find(st) != mp.end() and mp[st] != i and isPalindrome(en))
                    ans.push_back({i,mp[st]});
                
                if(mp.find(en) != mp.end() and mp[en] != i and isPalindrome(st))
                    ans.push_back({mp[en],i});
            }
        }
        
        if(mp.find("") != mp.end()){
            for(int i=0;i<words.size();i++){
                if(!words[i].empty() and isPalindrome(words[i]))                  
                    ans.push_back({i,mp[""]});                  
            }
        }
        return ans;
    }
};