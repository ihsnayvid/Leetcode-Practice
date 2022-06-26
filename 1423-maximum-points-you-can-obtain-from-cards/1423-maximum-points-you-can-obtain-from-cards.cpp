class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int i = 0, j = n-1;
        int sum = 0;
        for(auto i: cp) sum += i;
        int ans = INT_MIN, curr = 0;
        k = n - k;
        for(int i=0; i<k; i++) curr += cp[i];
        ans = sum - curr;
        for(int i=1; i<=n-k; i++){
            curr -= cp[i-1];
            curr += cp[i+k-1];
            ans = max(ans, sum - curr);
        }
        return ans;
    }
};