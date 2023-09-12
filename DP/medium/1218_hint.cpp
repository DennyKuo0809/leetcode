class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> max_len; 
        int res = 1;

        for(int i = 0 ; i < arr.size() ; i ++){
            if(max_len.find(arr[i]-difference) != max_len.end()){
                max_len[arr[i]] = max(
                    max_len[arr[i]],
                    max_len[arr[i] - difference] + 1
                );
                res = max(res, max_len[arr[i]]);
            }
            else{
                max_len[arr[i]] =  1;
            }
        }

        return res;
    }
};
