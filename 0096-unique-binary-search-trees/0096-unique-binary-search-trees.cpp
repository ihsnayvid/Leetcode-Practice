class Solution {
public:
    long nCr(int n, int r){
        if(r==0) return 1;
        vector<long> v(r+1,0);
        v[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=r;j>0;j--)
                v[j] = v[j] + v[j-1];
        }
        return v[r];
    }
    
    int numTrees(int n) {
        return nCr(2 * n, n) / (n+1);
    }
};