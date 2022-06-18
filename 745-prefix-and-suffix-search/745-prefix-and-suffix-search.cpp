class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        int n = words.size();
        string pre = "", suf = "";
        for(int i=0; i<n; i++){
            int l = words[i].size();
            for(int j=1; j<=l; j++){
                pre = words[i].substr(0,j);
                for(int k=l-1; k>=0; k--){
                    suf = words[i].substr(k);
                    mp[pre + "#" + suf] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix + "#" + suffix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */