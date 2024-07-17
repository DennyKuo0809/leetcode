class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftHighest = 0, rightHighest = 0;
        int ans = 0;
        while(l < r){
            if(height[l] <= height[r]){ 
                // There is a right side wall higher than leftHighest
                if(height[l] > leftHighest) leftHighest = height[l];
                else ans += (leftHighest - height[l]);
                l ++;
            }
            else {
                // There is a left side wall higher than rightHighest
                if(height[r] > rightHighest) rightHighest = height[r];
                else ans += (rightHighest - height[r]);
                r --;
            }
        }
        return ans;
    }
};
