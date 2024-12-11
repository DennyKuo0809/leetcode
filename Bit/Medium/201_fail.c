#define setBit(n, x) ((n) |= ((1) << (x)))
#define checkBit(n, x) ((((n) >> (x)) & (1)) == (1))
int rangeBitwiseAnd(int left, int right) {
    int ans = 0;
    for(int x = 31 ; x >= 0 ; x --){
        if(checkBit(right, x)){
            if(!checkBit(left, x)) break;
            setBit(ans, x);
        }
    }
    return ans;
}
