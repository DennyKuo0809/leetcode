/* dp[i][j] = longest common sub-sequence of text1[0:i] and text2[0:j] */
class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));

        for(int i = 0 ; i < text1.size() ; i ++){
            for(int j = 0 ; j < text2.size() ; j ++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                dp[i+1][j+1] = max(
                    dp[i+1][j+1],
                    max(dp[i][j+1], dp[i+1][j])
                );
            }
        }

        return dp[text1.size()][text2.size()];
    }
};
