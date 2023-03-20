class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;

        for(int i = 0 ; i < len ; i ++){
            nums[(nums[i] - 1) % len] += len;
            if((nums[(nums[i] - 1) % len] - 1) / len > 1){
                ret.push_back((nums[i] - 1) % len + 1);
            }
        }
        return ret;
    }
};
