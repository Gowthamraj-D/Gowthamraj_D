#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char)); // +2 for possible carry and null terminator
    result[maxLen + 1] = '\0';

    int carry = 0;
    int i = lenA - 1, j = lenB - 1, k = maxLen;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // If there's no carry, shift the result to the left
    if (k == 0) {
        for (int l = 0; l <= maxLen; l++) {
            result[l] = result[l + 1];
        }
    }

    return result;
}
