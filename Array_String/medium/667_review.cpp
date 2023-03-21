/* greedy */

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;

        int sum = 0, last = 1, next = 0;
        int find_upper = 1;
        int diff = k;
        
        ret.push_back(1);

        for(int diff = k ; diff > 0 ; diff --){
            next = last + (find_upper) * diff;
            ret.push_back(next);
            last = next;
            find_upper = -find_upper;
        }

        for(int i = k + 2 ; i <= n ; i ++) ret.push_back(i);

        return ret;
    }
};
