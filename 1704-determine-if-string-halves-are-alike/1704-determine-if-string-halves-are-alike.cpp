class Solution {
public:
    bool isVowel(char ch){
        char c = tolower(ch);
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    bool halvesAreAlike(string s) {
        int n = s.length(), c1 = 0, c2 = 0;
        for(int i=0; i<n/2; i++){
            if(isVowel(s[i])) c1++;
        }
        
        for(int i=n/2; i<n; i++){
            if(isVowel(s[i])) c2++;
        }
        
        return c1 == c2;
    }
};