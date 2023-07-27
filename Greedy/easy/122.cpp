class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0], sell = prices[0];
        for(int i = 1 ; i < prices.size() ; i ++){
            if(prices[i] < sell) {
                profit += sell - buy;
                buy = sell = prices[i];
            }
            else if(prices[i] > sell){
                sell = prices[i];
            }
        }
        profit += sell - buy;
        return profit;
    }
};
