char* toHex(int num) {
    if (num == 0) return "0"; 

    char * ans = (char *)malloc(9); 
    if (!ans) return NULL; 
    
    unsigned int num1 = num; 
    int index = 0; 

    while (num1) {
        int temp = num1 % 16; 
        num1 /= 16; 

        if (temp < 10) {
            ans[index++] = '0' + temp; 
        } else {
            ans[index++] = 'a' + (temp - 10); 
        }
    }

    ans[index] = '\0'; 

    for (int i = 0; i < strlen(ans) / 2; i++) {
        char temp = ans[i]; 
        ans[i] = ans[strlen(ans) - 1 - i]; 
        ans[strlen(ans) - 1 - i] = temp; 
    }

    return ans; 
}
