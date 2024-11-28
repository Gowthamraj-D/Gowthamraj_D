void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char* s, int sSize){
    int starting = 0, ending = sSize - 1;
    while (starting < ending){
        swap(&s[starting++], &s[ending--]);
    }
}
