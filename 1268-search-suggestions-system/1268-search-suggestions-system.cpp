class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        
        for(int i=1; i<=searchWord.length(); i++){
            string search = searchWord.substr(0,i);
            vector<string> temp;
            for(auto x: products){
                if(x.substr(0,i) == search){
                    temp.push_back(x);
                }
                if(temp.size() >= 3) break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};