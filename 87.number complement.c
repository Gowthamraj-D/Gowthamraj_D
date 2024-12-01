int complement(int n){
    int x = 0,complement=0;
    while (n > 0) {
       if(n % 2 == 0) complement += pow(2,x);
       x++;
       n = n / 2;
    }
    return complement;
}
int findComplement(int num) {
    return complement(num);
}
