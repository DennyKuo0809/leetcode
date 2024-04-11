class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length()) return "0";
        stack<int> s;
        int d = k;
        for(int n: num){
            while(!s.empty() && s.top() > n && d > 0) {
                d --;
                s.pop();
            }
            s.push(n);
        }
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        ans = ans.substr(0, num.length()-k);
        /* Remove the leading zeros */
        for(auto it = ans.begin() ; it != ans.end()-1 ;){
            if(*it == '0') ans.erase(it);
            else break;
        }
        
        return ans;
    }
};
