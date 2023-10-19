class Solution {
public:
    bool dp[101][101]; // dp(i,j) = s1[:i] and s2[:j] can form s3[:i+j]
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3) return false;
        dp[0][0] = true;
        for(int i = 0 ; i < l1 ; i ++) dp[i+1][0] = (dp[i][0] & s3[i] == s1[i]);
        for(int j = 0 ; j < l2 ; j ++) dp[0][j+1] = (dp[0][j] & s3[j] == s2[j]);
        for(int i = 0 ; i < l1 ; i ++){
            for(int j = 0 ; j < l2 ; j ++){
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == s3[i+j+1]) || (dp[i+1][j] && s2[j] == s3[i+j+1]);
            }
        }
        return dp[l1][l2];
    }
};
