// Create integer for divisor sum set equal to 1.
// loop from 2 to 1/2 the integer inclusive.
// for each number, if num%number == 0 add it to the divisor sum
// return divisorsum == num

bool checkPerfectNumber(int num) {
    if (num == 1) return false;
    int divSum = 1;
    for (int i = 2; i<=num/2; i++) {
        if (num%i == 0) divSum += i;
    }
    return divSum == num;
}
