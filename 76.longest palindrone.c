int longestPalindrome(char* s) {
    int cnt_arr[256] = {0};
    int cnt = 0, odd_cnt = 0;

    if(strlen(s) == 1) {
        return 1;
    }

    for(int i = 0; i < strlen(s); i++) {
        cnt_arr[s[i]]++;
    }
    for(int i = 0; i < 256; i++) {
        if(cnt_arr[i] % 2 == 0) {
            cnt += cnt_arr[i];
        }
        else {
            cnt += cnt_arr[i] - 1;
            odd_cnt = 1;
        }
    }

    if(odd_cnt == 1) {
        return cnt+1;
    }
    else {
        return cnt;
    }
}
