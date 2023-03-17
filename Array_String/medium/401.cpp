/* Combination */

class Solution {
public:
    vector<string> ret;
    int comb[10];
    int num[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
    bool used[10];
    int hour = 0, minute = 0;

    void C_10_(int low, int d, int n){
        if(d == n){
            hour = 0;
            minute = 0;
            for(int i = 0 ; i < n ; i ++){
                if(comb[i] < 4){
                    hour += num[comb[i]];
                    if(hour > 11) return;
                }
                else{
                    minute += num[comb[i]];
                    if(minute > 59) return;
                }
            }
            string m = to_string(minute);
            if(minute < 10) m = "0" + m;
            ret.push_back(to_string(hour) + ":" + m);
        }
        for(int i = low ; i < 10 ; i ++){
            if(!used[i]){
                used[i] = true;
                comb[d] = i;
                C_10_(i+1, d + 1, n);
                used[i] = false;
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        memset(used, 0, sizeof(used));
        C_10_(0, 0, turnedOn);
        return ret;
    }
};
