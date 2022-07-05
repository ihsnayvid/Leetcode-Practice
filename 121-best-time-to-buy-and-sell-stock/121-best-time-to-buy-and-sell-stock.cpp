class Solution {
public:
    //max of ( curr price - min till now)
    int maxProfit(vector<int>& prices){
        int buy = INT_MAX, ans = 0;
        
        for(int i=0; i<prices.size(); i++){
            buy = min(buy,prices[i]);
            ans = max(ans, prices[i] - buy);
        }
        return ans;
    }
};