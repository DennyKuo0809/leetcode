class NumArray {
public:
    vector<int> prefix_sum; // Length = nums.size() + 1

    NumArray(vector<int>& nums) {
        int s = nums[0];
        prefix_sum.push_back(0);
        prefix_sum.push_back(nums[0]);
        for(int i = 1 ; i < nums.size() ; i ++){
            s += nums[i];
            prefix_sum.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right+1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
