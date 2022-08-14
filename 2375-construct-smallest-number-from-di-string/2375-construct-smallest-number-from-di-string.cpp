class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        int n = pattern.size();
        for(int i=0; i<=pattern.size(); i++){            
            while(pattern[i] == 'I'){
                ans += (char) ((i+1) + '0');
                i++;
            }

            int c = 0;
            while(pattern[i] == 'D'){
                i++;
                c++;
            }
            
            int x = i+1;
            c++;
            while(c--){
                ans += (char)(x + '0');
                x--;
            }            
        }
        return ans;
    }
};