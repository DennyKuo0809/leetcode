class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        int max_sum = nums[0], min_sum = nums[0];
        int total_sum = 0;


        for(int i = 0 ; i < nums.size() ; i ++){
            total_sum += nums[i];

            if(sum1 + nums[i] < 0){
                max_sum = max(max_sum, nums[i]);
                sum1 = 0;
            }
            else{
                sum1 += nums[i];
                max_sum = max(max_sum, sum1);
            }

            if(sum2 + nums[i] > 0){
                min_sum = min(min_sum, nums[i]);
                sum2 = 0;
            }
            else{
                sum2 += nums[i];
                min_sum = min(min_sum, sum2);
            }
        }

        int take_away_min = (total_sum == min_sum) ? (max_sum) : (total_sum - min_sum);
        return max(max_sum, take_away_min);
    }
};
