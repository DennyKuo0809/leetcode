class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int cnt = 1;
        int cloest = 1, farest = nums[0];
        while(farest < nums.size() - 1){
            int nc = farest + 1, nf = farest + 1;
            for(int i = cloest ; i <= farest ; i ++) nf = max(nf, nums[i] + i); 
            cnt ++;
            cloest = nc;
            farest = nf;
        }
        return cnt;
    }
};
