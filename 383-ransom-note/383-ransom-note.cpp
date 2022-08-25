class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mg;
        for(auto i: magazine) mg[i]++;
        
        for(auto i: ransomNote){
            if(mg[i] > 0)
                mg[i]--;
            else
                return false;
        }
        return true;
    }
};