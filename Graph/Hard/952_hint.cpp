/*
  Employ Union-Find algorithm
  Union the number with their factor rather than other numbers to eliminate the complexity of finding gcd.
*/

class Solution {
public:

    int group[100001];
    int size[100001];
    int g_size[100001];

    int find(int p){
        if(group[p] == p) return p;
        else return group[p] = find(group[p]);
    }

    void merge(int n, int m){
        int pn = find(n);
        int pm = find(m);
        if(pn == pm) return;
        if(g_size[pn] >= g_size[pm]) {
            group[pm] = pn;
            g_size[pn] += g_size[pm];
            size[pn] += size[pm];
        }
        else {
            group[pn] = pm;
            g_size[pm] += g_size[pn];
            size[pm] += size[pn];
        }
    }


    int largestComponentSize(vector<int>& nums) {
        int len = nums.size();

        for(int i = 1 ; i <= 1e5 ; i ++){
            group[i] = i;
            g_size[i] = 1;
        }

        for(auto num: nums){
            size[num] = 1;
        }

        for(auto num: nums){
            for(int j = 2 ; j * j <= num ; j ++){
                if(num % j == 0){
                    merge(j, num);
                    merge(num/j, num);
                }
            }
        }

        int max_size = 1;
        for(auto num: nums){
            max_size = max(max_size, size[find(num)]);
        }
        return max_size;
    }
};
