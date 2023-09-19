class Solution {
public:
    int rob_line(vector<int>& nums, int begin, int end) {
        int rob = 0, non_rob = 0;
        int tmp;
        for(int i = begin ; i < end ; i ++){
            tmp = rob;
            rob = non_rob + nums[i];
            non_rob = max(tmp, non_rob);
        }
        return max(rob, non_rob);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(
            rob_line(nums, 0, nums.size()-1),
            rob_line(nums, 1, nums.size())
        );
    }
};
