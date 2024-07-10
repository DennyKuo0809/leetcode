class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 100;
        int ans = 1;
        for(int i = 1 ; i < nums.size() ; i ++){
            if(nums[i] == nums[i-1]){
                if(p >= i) p = i;
            }
            else{
                ans ++;
                if(p < i) {
                    nums[p] = nums[i];
                    p ++;
                }
            }
        }
        return ans;
    }
};
