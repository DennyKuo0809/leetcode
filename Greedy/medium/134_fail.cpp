/****************************
* All prefix should >= 0
*****************************/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sg = 0, sc = 0;
        int sd = 0;
        int ans = 0;
        for(int i = 0 ; i < gas.size() ; i ++){
            sg += gas[i];
            sc += cost[i];
            sd += (gas[i] - cost[i]);
            if(sd < 0){
                ans = i + 1;
                sd = 0;
            }
        }
        return (sg < sc)? (-1) : ans;
    }
};
