class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sellStock = 0, keepStock = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            sellStock = max(sellStock, keepStock + prices[i] - fee);
            keepStock = max(keepStock, sellStock - prices[i]);
        }
        return sellStock;
    }
};