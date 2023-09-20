/***********************************************************************
 * "The test cases are generated so that the given input 
 * always makes it possible.", this description gives that:
 * 
 *      The swap / not swap on index i can always make two array[0:i] be 
 *      strictly increasing.
 *
 * Note that this can't be solved by greedy, considering following testcase
 *      
 *      nums1 = [4, 4, 5, 6, 7, 8]
 *      nums2 = [3, 5, 6, 7, 8, 9]
 *
 * The swap should be perfromed on index 0 to minimize the number of swap.
 * The number of swap may not be minimized if the swap only performed on 
 * demand. Both swap and no swap on certain index should be considered.
 ************************************************************************/


class Solution {
public:
    struct meta{
        int num_swap;
        int max1;
        int max2;
    };

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        struct meta do_swap[2] = {
            {1, nums2[0], nums1[0]},
            {0, 0, 0}
        };
        struct meta no_swap[2] = {
            {0, nums1[0], nums2[0]},
            {0, 0, 0}
        };
        int len = nums1.size();

        /* DP */
        for(int i = 1 ; i < len ; i ++){
            /* Do swap on index i */
            do_swap[i&1].max1 = nums2[i];
            do_swap[i&1].max2 = nums1[i];
            if(nums2[i] <= do_swap[(i-1)&1].max1 || nums1[i] <= do_swap[(i-1)&1].max2){
                do_swap[i&1].num_swap = no_swap[(i-1)&1].num_swap + 1;
            }
            else if(nums2[i] <= no_swap[(i-1)&1].max1 || nums1[i] <= no_swap[(i-1)&1].max2){
                do_swap[i&1].num_swap = do_swap[(i-1)&1].num_swap + 1;
            }
            else {
                do_swap[i&1].num_swap = 1 + min(
                    do_swap[(i-1)&1].num_swap,
                    no_swap[(i-1)&1].num_swap
                );
            }

            /* Not swap on index i */
            no_swap[i&1].max1 = nums1[i];
            no_swap[i&1].max2 = nums2[i];
            if(nums1[i] <= do_swap[(i-1)&1].max1 || nums2[i] <= do_swap[(i-1)&1].max2){
                no_swap[i&1].num_swap = no_swap[(i-1)&1].num_swap;
            }
            else if(nums1[i] <= no_swap[(i-1)&1].max1 || nums2[i] <= no_swap[(i-1)&1].max2){
                no_swap[i&1].num_swap = do_swap[(i-1)&1].num_swap;
            }
            else {
                no_swap[i&1].num_swap = min(
                    do_swap[(i-1)&1].num_swap,
                    no_swap[(i-1)&1].num_swap
                );
            }
        }

        return min(
            do_swap[(len-1) & 1].num_swap,
            no_swap[(len-1) & 1].num_swap
        );
    }
};
