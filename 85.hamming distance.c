int hammingDistance(int x, int y){
    int d=0,n=x^y;
    while(n){
        n&=n-1;
        d++;
    }
    return d;
}
