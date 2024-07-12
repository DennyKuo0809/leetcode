/* Do it in-place */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotate = k % (int(nums.size()));
        if(!rotate) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + rotate);
        reverse(nums.begin() + rotate, nums.end());
    }
};
