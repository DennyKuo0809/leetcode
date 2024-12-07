class Solution {
public:
    stack<int> s;
    int ans[100001];
    int totalSteps(vector<int>& nums) {
        int ret = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            ans[i] = 0;
            while(!s.empty()){
                if(nums[s.top()] <= nums[i]) {
                    ans[i] = max(ans[i], ans[s.top()]);
                    s.pop();
                }
                else break;
            }
            if(!s.empty()) ans[i] ++;
            ret = max(ret, ans[i]);
            s.push(i);
        }

        return ret;
    }
};
