int arrangeCoins(int n) {
    int count = 0;
    while(n>0){
        count++;
        n = n - count - 1;  
    }
    return count;
}
