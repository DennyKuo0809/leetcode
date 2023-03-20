/*  Boyer–Moore majority vote algorithm */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int can1, can2;
        int cnt1 = 0, cnt2 = 0;
        int len = nums.size();
        int i = 1;
        can1 = nums[0];
        cnt1 = 1;
        while(i < len){
            if(nums[i] == can1){
                cnt1 ++;
                i ++;
            }
            else{
                can2 = nums[i];
                cnt2 = 1;
                i ++;
                break;
            }
        }

        for(; i < len ; i ++){
            if(nums[i] == can1){
                cnt1 ++;
            }
            else if(nums[i] == can2){
                cnt2 ++;
            }
            else if(!cnt1){
                can1 = nums[i];
                cnt1 ++;
            }
            else if(!cnt2){
                can2 = nums[i];
                cnt2 ++;
            }
            else if(nums[i] != can1 && nums[i] != can2){
                cnt1 --;
                cnt2 --;
            }
        }

        cnt1 = cnt2 = 0;

        for(int i = 0 ; i < len ; i ++){
            if(nums[i] == can1){
                cnt1 ++;
            }
            else if(nums[i] == can2){
                cnt2 ++;
            }
        }
        if(cnt1 > len / 3){
            ret.push_back(can1);
        }
        if(cnt2 > len / 3){
            ret.push_back(can2);
        }
        return ret;
    }
};
