class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, non_rob = 0;
        int tmp;
        for(int i = 0 ; i < nums.size() ; i ++){
            tmp = rob;
            rob = non_rob + nums[i];
            non_rob = max(tmp, non_rob);
        }
        return max(rob, non_rob);
    }
};
