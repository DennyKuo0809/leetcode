class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> ans(2,0);
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                ans[0] = l + 1;
                ans[1] = r + 1;
                return ans;
            }
            else if(sum < target){
                l ++;
            }
            else r --;
        }
        return ans;
    }
};
