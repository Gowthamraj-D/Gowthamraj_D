int divide(int A, int B) {
    int ans = 0, sign = A > 0 == B > 0 ? 1 : -1;
    // corner cases for using integer and not long:
    if (B == INT_MIN) {
        return A == B;
    }

    if (A == INT_MIN) {
        if (B == 1) {
            return INT_MIN;
        } else if (B == -1) {
            return INT_MAX;
        } else {
            A += abs(B), ans++;
        }
    }

    // Perform the division iteratively, by using bit shifting and subtraction:
    // We are looking for the largest powers of 2 (i) such that A shifted right by i bits is still greater than or equal to B.
    A = abs(A), B = abs(B);    
    for (int i = 0; A >= B; i = 0) {
        while ((A >> i) >= B) { 
            i++;
        }
        // This is equivalent to subtracting B * (2^(i-1)) from A.
        A -= B << i - 1;
        // Add 2^(i-1) to the result
        ans += 1 << i - 1;
    }

    return sign < 0 ? -ans : ans;
}
