/* DP */

class Solution {
public:
    int num[101][101][2];
    int countSubstrings(string s, string t) {
        int ret = 0;

        for(int i = 0 ; i < s.length() ; i ++){
            for(int j = 0 ; j < t.length() ; j ++){
                num[i+1][j+1][0] = (s[i] == t[j])? (num[i][j][0] + 1) : 0;
                num[i+1][j+1][1] = (s[i] == t[j])? (num[i][j][1]) : (num[i][j][0] + 1);
                ret += num[i+1][j+1][1];
            }
        }

        return ret;
    }
};
