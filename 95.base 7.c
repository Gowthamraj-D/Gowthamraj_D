char* convertToBase7(int num) {
    int sz = 0;
    char *v = malloc(16);

    int mask = num >> 31;
    num = (num ^ mask)-mask;
	int neg = !!mask;
    v[sz] = '-';
    sz |= neg; /* sz += 1 */
    
    do {
        v[sz++] = (num % 7) + '0'; 
        num /= 7;
    } while(num);

    for(int i = neg, j = sz - 1; i < j; i++, j--) {
        char t = v[i];
        v[i] = v[j];
        v[j] = t;
    }   
    v[sz] = '\0';

    return v;
}
