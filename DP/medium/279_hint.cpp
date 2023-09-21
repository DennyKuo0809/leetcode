class Solution {
public:
    int dp[10001];
    int numSquares(int n) {
        int ans = 10000;
        dp[0] = 0;
        for(int i = 1 ; i <= n ; i ++){
            int m = 10000;
            for(int j = 1 ; j * j <= i ; j ++){
                m = min(m, dp[i-j*j]);
            }
            dp[i] = m + 1;
            if(i == n) ans = min(ans, dp[i]);
        }

        return ans;
    }
};
