class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int p = 100000;
        int ans = nums.size();
        for(int i = 1 ; i < nums.size() ; i ++){
            if(nums[i] == nums[i-1]){
                cnt ++;
                if(cnt > 2){
                    ans --;
                    if(p >= i) p = i;
                }
                else if(p < i){
                    nums[p] = nums[i];
                    p ++;
                }
            }
            else {
                cnt = 1;
                if(p < i){
                    nums[p] = nums[i];
                    p ++;
                }
            }
        }

        return ans;
    }
};
