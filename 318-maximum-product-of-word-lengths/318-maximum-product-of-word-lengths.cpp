class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> dec(n);
        for(int i=0; i<n; i++){
            
            for(auto x: words[i])
                dec[i] |= 1 << (x - 'a');
            
            for(int j=0; j<i; j++){
                if(!(dec[i] & dec[j])){
                    int currProd = words[i].length() * words[j].length();
                    ans = max(ans, currProd);
                }                    
            }            
        }
        
        return ans;
    }
};