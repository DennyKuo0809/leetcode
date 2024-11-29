class Solution {
public:
    int num[20];

    int numTrees(int n) {
        num[0] = 1;
        num[1] = 1;
        for(int i = 2 ; i <= n ; i ++){
            for(int j = 0 ; j < i ; j ++){
                num[i] += (num[j] * num[i-j-1]);
            }
        }
        return num[n];
    }
};
