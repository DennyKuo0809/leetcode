int hammingWeight(int n) {
    int ans = 0;
    while(n){
        ans ++;
        n &= ~(-n);
    }
    return ans;
}
