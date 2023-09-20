class Solution {
public:
    struct ways {
        long long int full;
        long long int low_empty;
        long long int high_empty;
    };
    struct ways w[1001]; 
    const int mod = 1e9+7;
    int numTilings(int n) {
        w[0] = {0, 0, 0};
        w[1] = {1, 0, 0};
        w[2] = {2, 0, 0};
        w[3] = {5, 2, 2};
        for(int i = 4 ; i <= n ; i ++){
            w[i] = {
                (w[i-1].full + w[i-2].full + w[i-1].low_empty + w[i-1].high_empty) % mod,
                (w[i-2].full + w[i-1].low_empty) % mod,
                (w[i-2].full + w[i-1].high_empty) % mod
            };
        }
        return w[n].full;
    }
};
