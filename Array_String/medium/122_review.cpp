class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sellP always >= buyP
        prices.push_back(-1);
        int P = 0;
        int buyP = prices[0], sellP = prices[0];
        for(int i = 1 ; i < prices.size() ; i ++){
            if(prices[i] < prices[i-1]){
                P += (sellP - buyP);
                buyP = sellP = prices[i];
            }
            sellP = max(sellP, prices[i]);
        }
        return P;
    }
};
