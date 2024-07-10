class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 100;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i] == val){
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
