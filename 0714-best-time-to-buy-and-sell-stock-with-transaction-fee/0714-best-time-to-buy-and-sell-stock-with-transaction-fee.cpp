class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN, sell = 0;
        for(auto i: prices){
            int temp = sell;
            sell = max(sell, buy + i);
            buy = max(buy, temp - i - fee);
        }
        return sell;
    }
};