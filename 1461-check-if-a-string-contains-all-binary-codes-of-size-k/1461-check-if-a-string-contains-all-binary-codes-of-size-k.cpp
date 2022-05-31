class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        vector<int> v(pow(2,k),0);
        int n = s.length();
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