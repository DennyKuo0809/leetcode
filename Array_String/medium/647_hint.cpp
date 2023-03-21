/* DP */

class Solution {
public:
    bool is_palindrome[1000][1000];
    int countSubstrings(string s) {
        memset(is_palindrome, 0, sizeof(is_palindrome));
        int len = s.length();
        int ret = 1;

        is_palindrome[0][0] = true;
        for(int i = 1 ; i < len ; i ++){
            is_palindrome[i][i] = true;
            ret ++;
            if(s[i] == s[i-1]) {
                is_palindrome[i-1][i] = true;
                ret ++;
            }
        }

        for(int l = 2 ; l < len ; l ++){
            for(int i = 0 ; i < len - l ; i ++){
                if(is_palindrome[i+1][i+l-1] && s[i] == s[i+l]){
                    is_palindrome[i][i+l] = true;
                    ret ++;
                }
            }
        }

        
        return ret;
    }
};
