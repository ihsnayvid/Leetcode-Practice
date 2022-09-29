class Solution {
public:
    int maxArea(vector<int>& h) {
        int low = 0, high = h.size() - 1;
        int ans = INT_MIN;
        while(low < high){
            int l = min(h[low], h[high]);
            int b = high - low;
            ans = max(ans, l * b);
            if(h[low] < h[high]) low ++;
            else high --;
        }
        return ans;
    }
};