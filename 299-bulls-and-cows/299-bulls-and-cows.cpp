class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp, mg;
        if(secret.size() != guess.size()) return "0A0B";
        
        int x = 0, y = 0;
        string ans = "";
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i])
                x++;
            else
                mp[secret[i]]++;
        }
        
        for(int i=0; i<secret.size(); i++){
            if(secret[i] != guess[i] and mp[guess[i]] > 0){
                mp[guess[i]]--;
                y++;
            }                
        }
        return to_string(x) + "A" + to_string(y) + "B";
        
    }
};