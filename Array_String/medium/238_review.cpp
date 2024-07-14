class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int l = nums.size();
        ans.push_back(nums[l-1]);
        for(int i = l-2 ; i >= 0 ; i --){
            ans.push_back(nums[i] * ans[l-2-i]);
        }
        reverse(ans.begin(), ans.end());
        int m = nums[0];

        ans[0] = ans[1];
        for(int i = 1 ; i < nums.size()-1 ; i ++){
            ans[i] = m * ans[i+1];
            m *= nums[i];
        }
        ans[nums.size()-1] = m;

        return ans;
    }
};
