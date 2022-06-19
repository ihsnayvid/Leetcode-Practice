class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(auto p:products){
            string s= "";
            for(int i=0; i<p.size(); i++){
                s+=p[i];
                if(mp[s].size() < 3) mp[s].push_back(p);
            }
        }
        
        string s ="";
        for(int i=0; i<searchWord.size(); i++){
            s += searchWord[i];
            ans.push_back(mp[s]);
        }
        return ans;
    }
};