/******************************************************************************************************
*
* dp_no_change[i&1] = The least steps need to make arr1[i] strictly increasing by left arr1[i] not changed
* dp[i&1][j] = The least steps need to make arr1[i] strictly increasing by assign arr2[j] to arr1[i]
* But taking the concept that 
*    dp[i&1][j] = min(dp_no_change[(i-1)&1], min(dp[(i-1)&1][0], ..., dp[(i-1)&1][k])) + 1 ,
*      where arr2[k] < arr2[j] and arr2[k+1] >= arr2[j]
* Hence, we can lowering the time complexity by store min(dp[i&1][0], ..., dp[i&1][j-1]) at dp[i&1][j]
********************************************************************************************************/


class Solution {
public:
    unsigned int dp[2][2000];
		unsigned int dp_not_change[2];
		int upper_for_arr2[2000];
		int binary_search(int val, vector<int> arr2, int left, int right){
			int l = left, r = right;
			int mid;
			while(l < r){
				mid = (l + r) / 2;
				if(arr2[mid] < val) l = mid + 1;
				else r = mid;
			}
			return l;
		}

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
			sort(arr2.begin(), arr2.end());
			dp_not_change[0] = 0;
			for(int j = 0 ; j < arr2.size() ; j ++){
					upper_for_arr2[j] = binary_search(arr2[j], arr2, 0, j);
					dp[0][j] = 1;
			}
			for(int i = 1 ; i < arr1.size() ; i ++){
				/* Do change */
				unsigned int lowest = INT_MAX;
				for(int j = 0 ; j < arr2.size() ; j ++){
					dp[i&1][j] = INT_MAX;
					if(arr1[i-1] < arr2[j]) dp[i&1][j] = dp_not_change[(i-1)&1] + 1;
					int upper = upper_for_arr2[j];
					if(upper > 0){
						dp[i&1][j] = min(dp[i&1][j], dp[(i-1)&1][upper-1] + 1);
					}
					lowest =  min(lowest, dp[i&1][j]);
					dp[i&1][j] = lowest;
				}

				/* Not change by element in arr2 */
				dp_not_change[i&1] = INT_MAX;
				if(arr1[i-1] < arr1[i]) dp_not_change[i&1] = dp_not_change[(i-1)&1];
				int upper = binary_search(arr1[i], arr2, 0, arr2.size());
				if(upper > 0){
					dp_not_change[i&1] = min(dp_not_change[i&1], dp[(i-1)&1][upper-1]);
				}
			}
			int res = min(dp[(arr1.size()-1)&1][arr2.size()-1], dp_not_change[(arr1.size()-1)&1]);
      return (res == INT_MAX)? (-1) : res;
    }
};
