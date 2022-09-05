class Solution {
public:
    bool isNice(string s){
        unordered_map<char, int> mp;
        for(auto i: s)
            mp[i]++;
    
        for(auto i: s){
            if(isupper(i)){
                // cout<<i<<" " << tolower(i)<<endl;
                if(mp.find(tolower(i)) == mp.end()) return false;
            }
            else{
                // cout<<i<<" "<<toupper(i)<<endl;
                if(mp.find(toupper(i)) == mp.end()) return false;
            }
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        
        int l = 0;
        string ans = "";
         
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<=s.size() - i; j++){
                string sub = s.substr(i,j);
                // cout<<sub<<endl;
                if(isNice(sub) and sub.length() > ans.length())
                    ans = sub;
            }
        }
        return ans;
    }
};