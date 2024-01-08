class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i ++){
            if(nums[i] <= 0 || nums[i] > n) nums[i] = 1e5 + 1;
        }

        for(int i = 0 ; i < n ; i ++){
            if(nums[i] != 1e5+1 && nums[i] != -(1e5+1)){
                int real_number = abs(nums[i]);
                if(nums[real_number-1] > 0){
                    nums[real_number-1] *= (-1);
                } 
            }
        }
        for(int i = 0 ; i < n ; i ++){
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};
