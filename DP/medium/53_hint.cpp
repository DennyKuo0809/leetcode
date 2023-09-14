class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int s = 0;
        for(int i = 0; i < nums.size() ; i ++){
            max_sum = max(
                max_sum,
                max(s+nums[i], nums[i]) 
                /* s always >= 0, 
                 * if s == 0 and nums[i] < 0, 
                 * compare nums[i] with max_sum */
            );
            if(s + nums[i] < 0) s = 0;
            else s += nums[i];
        }
        return max_sum;
    }
};
