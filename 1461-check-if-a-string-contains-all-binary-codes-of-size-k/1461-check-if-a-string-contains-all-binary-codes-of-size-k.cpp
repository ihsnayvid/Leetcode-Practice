class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(k > n) return false;
        vector<int> v((1 << k),0);        
        int dec=0;
        for(int i=0; i<=n-k; i++){
            string sub = s.substr(i,k);
            dec = stoi(sub,0,2);
            v[dec]++;
        }
        
        for(auto i:v){
            if(!i) return false;
        }
        return true;
    }
};