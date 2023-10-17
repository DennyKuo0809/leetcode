class Solution {
public:
    bool match[21][21];
    bool isMatch(string s, string p) {
        int ls = s.length(), lp = p.length();

        /* Initialization: Compared with empty string */
        match[0][0] = true;
        for(int i = 0 ; i < ls ; i ++) match[i+1][0] = false;
        bool non_star = false;
        for(int j = 0 ; j < lp ; j ++) {
            if(j > 0 && p[j] != '*' && p[j-1] != '*'){
                non_star = true;
                match[0][j+1] = false;
            }
            else if(!non_star) match[0][j+1] = (p[j] == '*');
            else match[0][j+1] = false;
        }

        /* DP */
        for(int i = 0 ; i < ls ; i ++){
            for(int j = 0 ; j < lp ; j ++){
                if(p[j] == '.'){
                    match[i+1][j+1] = match[i][j];
                }
                else if(p[j] == '*'){
                    /* 
                        star make empty string  || 
                        star make single char ||
                        star make multiple chars
                    */
                    bool empty = match[i+1][j-1];
                    bool single = match[i+1][j];
                    bool multiple = (p[j-1] == s[i] || p[j-1] == '.')? match[i][j+1] : false;
                    match[i+1][j+1] = empty || single || multiple;
                }
                else{
                    match[i+1][j+1] = (s[i] == p[j]) && match[i][j];
                }
            }
        }

        return match[ls][lp];
    }
};
