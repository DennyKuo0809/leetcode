class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() <= 1) return 0;

        int longest = 0;
        int i = 1;
        
        bool find_uphill = true, uphill = false;
        int len = 2;

        while(i < arr.size()){
            if(find_uphill){
                while(i < arr.size() && arr[i] <= arr[i-1]){
                    i ++;
                }
                find_uphill = false;
                uphill = true;
                len = 2;
            }
            else if(uphill){
                if(arr[i] == arr[i-1]){
                    find_uphill = true;
                    continue;
                }
                else if(arr[i] < arr[i-1]){
                    uphill = false;
                }
                len ++;
            }
            else{
                if(arr[i] >= arr[i-1]){
                    longest = max(longest, len);
                    if(arr[i] == arr[i-1]) {
                        find_uphill = true;
                        uphill = false;
                    }
                    else {
                        uphill = true;
                        len = 2;
                    }
                }
                else {
                    len ++;
                }
            }
            i ++;
        }
        // return longest;
        if(!find_uphill && !uphill) longest = max(longest, len);
        return longest;
    }
};
