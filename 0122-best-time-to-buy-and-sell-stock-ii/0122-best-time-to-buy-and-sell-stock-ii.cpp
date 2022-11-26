class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        for(int i=0; i<n-1; i++){
            int x = i;
            while(i < n-1 and prices[i] < prices[i+1])
                i++;                   
            ans += (prices[i] - prices[x]);
        }
        return ans;
    }
};