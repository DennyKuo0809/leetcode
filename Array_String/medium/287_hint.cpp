class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++){
            int num = nums[i] % (n+1);
            nums[num] += (n+1);
            if(nums[num] >= (n+1) * 2) return num ;
        }
        return -1;
    }
};
