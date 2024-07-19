/* KMP algorithm */
/* 
 * Find a certain pattern in a string.
 * Construct a failure function (array) for the pattern.
 * failure[i] means there exists a longest prefix of the pattern
 * which ends at index failure[i] matchs pattern[(i-failure[i]):(i+1)].
*/



    
class Solution {
public:
    int failure[10001];
    void construct(string s){
        int i = 1, j = 0;
        int m = s.length();

        while(i < m){
            if(s[i] == s[j]){
                failure[i] = j + 1;
                i ++;
                j ++;
            }
            else if(j > 0){
                j = failure[j - 1];
            }
            else{
                failure[i] = 0;
                i ++;
            }
        }
    }
    int strStr(string haystack, string needle) {
        memset(failure, 0, sizeof(int) * needle.length());
        construct(needle);
        int i = 0, j = 0;
        int m = needle.length(), n = haystack.length();
        while(i < n){
            if(haystack[i] == needle[j]){
                if(j == m - 1){
                    return i - j;
                }
                j ++;
                i ++;
            }
            else if(j > 0){
                j = failure[j - 1];
            }
            else{
                i ++;
            }
        }
        
        return -1;
    }
};
