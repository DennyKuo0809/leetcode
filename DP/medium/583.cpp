class Solution {
public:
    int dp[501][501]; // dp(i,j) = steps to make word1[:i] to word2[:i]
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        for(int i = 0 ; i < l1 ; i ++) dp[i+1][0] = i+1;
        for(int j = 0 ; j < l2 ; j ++) dp[0][j+1] = j+1;
        for(int i = 0 ; i < l1 ; i ++){
            for(int j = 0 ; j < l2 ; j ++){
                dp[i+1][j+1] = min(
                    ((word1[i] == word2[j])? (dp[i][j]) : (dp[i][j]+2)), // delete both if different
                    min(
                        dp[i][j+1] + 1, // Delete word1[i]
                        dp[i+1][j] + 1 // Delete word2[j]
                    )
                );
            }
        }
        return dp[l1][l2];
    }
};
