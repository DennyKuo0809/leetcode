class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.size() == 0) return ret;
        int low = nums[0], high = nums[0];

        for(int i = 1 ; i < nums.size() ; i ++){
            if(nums[i] == nums[i-1] + 1){
                high = nums[i];
            }
            else {
                if(low == high){
                    ret.push_back(to_string(low));
                }
                else{
                    ret.push_back(to_string(low) + "->" + to_string(high));
                }
                low = nums[i];
                high = nums[i];
            }
        }
        
        if(low == high){
            ret.push_back(to_string(low));
        }
        else{
            ret.push_back(to_string(low) + "->" + to_string(high));
        }

        return ret;
        
        
    }
};
