class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        int l = 0, r = n-1, left = 0, right = 0;
        while(l < r){
            if(h[l] <= h[r]){
                if(h[l] >= left) left = h[l];
                else ans += (left - h[l]);
                l++;
            }
            else{
                if(h[r] >= right) right = h[r];
                else ans += (right - h[r]);
                r--;
            }
        }
        return ans;
    }
};