class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyP = prices[0];
        int maxP = 0;
        for(int p: prices){
            buyP = min(p, buyP);
            maxP = max(p - buyP, maxP);
        }

        return maxP;
    }
};
