class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = h[0];
        suf[n-1] = h[n-1];
        
        for(int i=1; i<n; i++)
            pre[i] = max(h[i], pre[i-1]);
        for(int i=n-2; i>=0; i--)
            suf[i] = max(h[i], suf[i+1]);
        
        int total = 0;
        for(int i=0; i<n; i++){
            int trap = min(pre[i], suf[i]) - h[i];
            if(trap > 0) total += trap;
        }
        return total;        
    }
};