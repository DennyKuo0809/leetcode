/*
  Step 1. Find the longest prefix which is a palindrome. (This can be done by KMP)
  Step 2. Reverse the remain part and concate it in front of the original string.

  Implementation (KMP Algorithm):
    Performing failure function on "{original string}?{reverse string}".
    And the failure value of the last element represent that (the length of longest prefix which is a palindrome ) - 1.
    Which means that the suffix of reverse string is equivelant to the prefix of the original string with length as failure[-1].
*/

class Solution {
public:
    int failure[100005];
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string kmp = s + "?" + rev;

        /* Performing failure function */
        failure[0] = -1;
        for(int i = 1 ; i < kmp.length() ; i ++){
            int to_compare = failure[i-1] + 1;
            while(to_compare > 0 && kmp[to_compare] != kmp[i]) 
                to_compare = failure[to_compare-1] + 1;
            if(kmp[to_compare] == kmp[i]) failure[i] = to_compare;
            else failure[i] = to_compare - 1;
        }

        return rev.substr(0, s.length() - failure[kmp.size()-1] - 1) + s;
    }
};
