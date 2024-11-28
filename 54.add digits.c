int addDigits(int num){
    int sum = -99;
    int x = num;
    if (num == 0) return 0;

    while (sum / 10 != 0) {
        sum = 0;
        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }
        x = sum;
    }

    return sum;
   
}
