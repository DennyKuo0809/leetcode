class Solution {
public:
    bool isDecimal(string s, bool float_ok){
        if(s.length() == 0) return false;
        bool period = false;
        bool number = false;
        for(int i = 0 ; i < s.length() ; i ++){
            if(s[i] == '+' || s[i] == '-'){
                if(i != 0) return false;
            }
            else if(s[i] == '.'){
                if(!float_ok) return false;
                if(period) return false;
                period = true;
            }
            else if(s[i] - '0' < 0 || s[i] - '0' > 10) return false;
            else number = true;
        }
        return number;
    }

    bool isNumber(string s) {
        int n = s.length();
        for(int i = 0 ; i < n ; i ++){
            if(s[i] == 'e' || s[i] == 'E'){
                return isDecimal(s.substr(0, i), true) & isDecimal(s.substr(i+1), false);
            }
        }
        return isDecimal(s, true);
    }
};
