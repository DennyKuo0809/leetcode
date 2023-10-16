class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0); res.push_back(1);
        int length = 2;
        for(int i = 2 ; i <= n ; i ++){
            for(int j = length-1 ; j >= 0 ; j --){
                res.push_back(length + res[j]);
            }
            length *= 2;
        }
        return res;
    }
};
