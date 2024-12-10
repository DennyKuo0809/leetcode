char* addBinary(char* a, char* b) {
    int ia = strlen(a), ib = strlen(b);
    int ans_len = 2 + ((ia > ib)? ia : ib);
    char* ans = (char *)malloc(sizeof(char) * ans_len);
    ans[ans_len - 1] = '\0';
    int index = ans_len - 2;
    int carry = 0;
    ia --;
    ib --;
    while(index >= 0){
        if(ia >= 0) carry += a[ia--] - '0';
        if(ib >= 0) carry += b[ib--] - '0';
        ans[index--] = '0' + carry % 2;
        carry /= 2;
    }

    return (ans[0] == '0')? (ans+1) : ans;
}
