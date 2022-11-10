class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";
        for(auto i: s){            
            if(!st.empty() and st.back() == i)
                st.pop_back();
            else
                st.push_back(i);
        }
        return st;
    }
};