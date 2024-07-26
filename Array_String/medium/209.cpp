class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int left = 0, right = 1; // [left, right)
        int ans = 0;
        int l = nums.size();
        while(left < l && right <= l){
            if(sum < target){
                if(right == l) break;
                sum += nums[right];
                right ++;
            }
            else { // sum >= target
                if(!ans) ans = right - left;
                else ans = min(ans, right-left);
                sum -= nums[left];
                left ++;
            }
        }
        return ans;
    }
};
