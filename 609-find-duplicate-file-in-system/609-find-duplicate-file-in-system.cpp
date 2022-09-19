class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(auto s: paths){
            string root = "";
            int i = 0;
            while(s[i] != ' ')
                root += s[i++];
            i++;
            while(i<s.length()){
                if(s[i] == ' ') i++;
                string file = "";

                while(s[i] != '(')
                    file += s[i++];

                if(s[i] == '('){
                    i++;
                    string text = "";
                    while(s[i] != ')')
                        text += s[i++];
                    mp[text].push_back(root + "/" + file);
                }
                i++;
            }
        }
        vector<vector<string>> ans;
        for(auto i: mp){
            if(i.second.size() > 1)
                ans.push_back(i.second);
        }
        return ans;
    }
};