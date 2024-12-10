uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int i = 0 ; i < 32 ; i ++){
        ans = 2 * ans + ((n >> i) & (uint32_t)1);
    }
    return ans;
}
