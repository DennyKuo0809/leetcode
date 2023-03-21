/* Greedy */

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int last_valid_index = -1, len = 0;
        int ret = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i] >= left && nums[i] <= right){
                len ++;
                ret += len;
                last_valid_index = i;
            }
            else if(nums[i] < left){
                len ++;
                if(last_valid_index >= 0){
                    ret += len - (i - last_valid_index);
                }
            }
            else{
                len = 0;
                last_valid_index = -1;
            }
        }
        return ret;
    }
};
