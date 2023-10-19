class Solution {
public:
    unsigned long long int dp[1000]; 
    // dp(i,j) = number of t[:j] as substring in s[:i]. dp(i,j) is only from  dp(i-1,j) and dp(i-1,j-1), so we can make the space from O(n^2) to O(n) 
    int numDistinct(string s, string t) {
        memset(dp, 0, sizeof(int) * t.length());
        dp[0] = int(s[0] == t[0]);
        for(int i = 1 ; i < s.length() ; i ++){
            for(int j = t.length() - 1 ; j >= 0 ; j --){
                if(j > 0){
                    dp[j] = dp[j] + ((s[i] == t[j])?dp[j-1]:0);
                }
                else {
                    dp[j] = dp[j] + int(s[i] == t[j]);
                }
            }
        }
        return dp[t.length()-1];
    }
};
