/* s = "2-5g-3-J", k = 2
 * l = strlen(s) => 8, size = l + l / k + 1 => 13
 * *buffer(13) => □ □ □ □ □ □ □ □ □ □ □ □ □
 * *rbegin = *buffer + size - 1 => [13 - 1] => [12] 
 * *buffer(13) => □ □ □ □ □ 2 - 5 g - 3 J □
 *                0         e             b
 * size = rbegin - rend + 1 = 12 - 5 + 1 => 8
 * *output(8) =>            □ □ □ □ □ □ □ □
 * memcpy(output, rend, size)
 * *output(8) =>            2 - 5 g - 3 J □
 */
char * licenseKeyFormatting(char * s, int k){
    const int L = strlen(s), Lmax = L + L / k;
    char *buffer = calloc(Lmax + 1, sizeof(char));
    char *rbegin = buffer + Lmax, *rend = rbegin;
    for (int i = L - 1, j = 0; i >= 0; --i) {
        if (s[i] == '-') continue;
        if (j == k) *(--rend) = '-', j = 0;
        *(--rend) = toupper(s[i]), j += 1;
    }
    const int size = (rbegin - rend) + 1;
    char *output = calloc(size, sizeof(char));
    memcpy(output, rend, size); free(buffer);
    return output;
}
