class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> w1(words.begin(), words.end());
        set<string> w2(words.begin(), words.end());
        
        for(auto w: w1){
            for(int i=1; i<=w.size(); i++)
                w2.erase(w.substr(i));            
        }
        
        int ans = 0;
        for(auto w:w2)
           ans += w.length() + 1;   //+1 for '#' 
        
        return ans ;
    }
};