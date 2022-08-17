class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string,int> mp;
        
        for(auto i: words){
            string s = "";
            for(auto w: i)
                s += morse[w-'a'];
            mp[s]++;
        }
        
        return mp.size();
    }
};