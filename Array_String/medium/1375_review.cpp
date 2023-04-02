/* Greedy */

class Solution {
public:
    
    int numTimesAllBlue(vector<int>& flips) {
        int times = 0;
        int first_check = 1;

        for(int i = 0 ; i < flips.size() ; i ++){
            if(flips[i] > first_check){
                first_check = flips[i];
            }
            else if(i + 1 >= first_check){ /* flips[i] <= first_check */
                times ++;
                first_check = i + 2;
            }
        }

        return times;
    }
};
