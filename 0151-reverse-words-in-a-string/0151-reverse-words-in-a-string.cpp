class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str = "", word;
        while(ss >> word)
            str = word + ' ' + str;  
        
        str.pop_back();
        return str;
    }
};