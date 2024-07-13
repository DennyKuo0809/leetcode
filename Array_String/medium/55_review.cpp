class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJ = 1;
        for(int i = nums.size() - 2 ; i >= 0 ; i --){
            if(nums[i] < minJ) {
                if(i == 0) return false;
                minJ ++;
            }
            else minJ = 1;
        }
        return true;
    }
};
