class Solution {
public:
    string reverseWords(string s) {
        // stack<string> st;
        // int i = 0, n = s.size();
        // string str = "";
        // while(i < n){
        //     str += s[i];
        //     if(s[i] == ' '){
        //         st.push(str);
        //         str = "";
        //     }
        //     i++;
        // }
        // str += ' ';
        // while(!st.empty()){
        //     str += st.top();
        //     st.pop();
        // }
        // return str;
        
        stringstream ss(s);
        string str = "", word;
        while(ss >> word){
            str = word + ' ' + str;  
        }
        str.pop_back();
        return str;
    }
};