class Solution {
public:
    int cnt[10001];
    int deleteAndEarn(vector<int>& nums) {
        int m = 10001, M = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            m = min(nums[i], m);
            M = max(nums[i], M);
            cnt[nums[i]] ++;
        }

        
        /* DP */
        int non = 0;
        cnt[m] *= m;
        for(int i = m+1 ; i <= M ; i ++){
            cnt[i] = cnt[i] * i  + non;
            non = max(non, cnt[i-1]);
        }
        return max(non, cnt[M]);
    }
};
