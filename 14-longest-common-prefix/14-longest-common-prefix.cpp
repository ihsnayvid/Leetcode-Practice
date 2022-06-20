class Solution {
public:
    static bool cmp(string a, string b){
        return a.size()<b.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(), cmp);
        int l = strs[0].length();
        
        string ans = "";
        while(l){
            bool same = true;
            string search = strs[0].substr(0,l);
            for(int i=1; i<strs.size(); i++){
                if(strs[i].substr(0,l) != search){
                    same = false;
                    break;
                }
            }
            if(same){
                ans += search;
                return ans;
            }
            l--;
        }
        return ans;
    }
};