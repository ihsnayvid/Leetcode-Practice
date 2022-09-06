class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,bool> mapped;
        
        unordered_map<int, string> str;
        s += ' ';
        int j = 0, k = 0;
        
        //d o g   c a t   c a t     d  o  g
        //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        
        for(int i=0; i<=s.size(); i++){
            if(s[i] == ' '){
                // cout<<j<<" - " <<i<<endl;
                str[k] = s.substr(j,i-j+1);
                j = i+1;
                k++;
            }
        }
        if(pattern.size() != str.size()) return false;
        
//         for(auto i: str)
//             cout<<i.first<<" : "<<i.second<<endl;
        
        for(int i=0; i<pattern.size(); i++){
            char c = pattern[i];
            auto pfound = mp.find(c);
            auto sfound = mapped.find(str[i]);
            
            if(pfound == mp.end()){
                if(sfound != mapped.end()) return false;
                else{
                    mp[c] = str[i];
                    mapped[str[i]] = true;
                }
            }
            else if(mp[c] != str[i]) return false;
        } 
        return true;
    }
};