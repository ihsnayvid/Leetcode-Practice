class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcut, vector<int>& vcut) {
        long long mod = 1000000007;
        hcut.push_back(h);
        vcut.push_back(w);
        sort(hcut.begin(),hcut.end());
        sort(vcut.begin(),vcut.end());
        
        int mxh = hcut[0], mxv = vcut[0];
        
        for(int i=1; i<hcut.size(); i++)
            mxh = max(mxh, hcut[i] - hcut[i-1]);
        for(int i=1; i<vcut.size(); i++)
            mxv = max(mxv, vcut[i] - vcut[i-1]);
        
        return ((mxh % mod) * (mxv  % mod)) % mod;
    }
};