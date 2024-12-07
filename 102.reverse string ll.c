void revers(char* front, int k){
    char* back = front;
    for(int j = 0, r = k-1; j < (k/2); j++, r--){
        printf("[%c, %c]", front[j], back[r]);
        char t = front[j];
        front[j] = back[r]; 
        back[r] = t;  
    }
    // return front;
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    char* temp = s;
    for(int i = 0; i < len; i += 2*k){
        if(len-i >= 2*k){
            revers(temp, k);
            temp += 2*k;
        }
        else if(len-i >= k){
            revers(temp, k);
            break;
        }
        else{
            revers(temp, len-i);
            break;
        }
    }
    return s;
}
