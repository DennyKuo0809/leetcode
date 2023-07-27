class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi, second_maxi;
        if(nums[0] > nums[1]){
            maxi = 0;
            second_maxi = 1;
        }
        else{
            maxi = 1;
            second_maxi = 0;
        }
        for(int i = 2 ; i < nums.size() ; i ++){
            if(nums[i] > nums[maxi]){
                second_maxi = maxi;
                maxi = i;
            }
            else if(nums[i] > nums[second_maxi]){
                second_maxi = i;
            }
        }
        if(nums[maxi] >= 2 * nums[second_maxi]) return maxi;
        return -1;
    }
};
