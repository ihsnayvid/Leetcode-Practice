class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n/2){
            int profit = 0;
            for(int i=1; i<n; i++)
              profit += max(prices[i] - prices[i-1], 0);
            return profit;
        }
        vector<int>buy(k+1, INT_MAX);
        vector<int>sell(k+1, 0);
        for(int i=0; i<n; i++){
            for(int j=1; j<=k; j++){
                buy[j] = min(buy[j], prices[i] - sell[j-1]);
                sell[j] = max(sell[j], prices[i] - buy[j]);
            }
        }
        return sell[k];
    }
};