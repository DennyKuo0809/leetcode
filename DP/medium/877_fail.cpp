class Solution {
public:
    int dp[500][500]; // dp[i][j] means that in the interval [i, j], the number of piles that took by Alen than Bob did
    bool stoneGame(vector<int>& piles) {
        // initialize
        for(int i = 0 ; i < piles.size() ; i ++){
            dp[i][i] = piles[i];
            if(i != piles.size()-1) dp[i][i+1] = max(piles[i], piles[i+1]);
        }

        // dp
        for(int len = 2 ; len < piles.size() ; len ++){
            for(int start = 0 ; start < piles.size() - len ; start ++){
                int end = start + len;
                dp[start][end] = max(
                    piles[start] + min(dp[start+1][end-1], dp[start+2][end]),
                    piles[end] + min(dp[start+1][end-1], dp[start][end-2])
                );
            }
        }

        return (dp[0][piles.size()-1] > 0);
    }
};
