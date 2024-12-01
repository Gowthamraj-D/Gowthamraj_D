void reverseString(char *str)
{
    int len = strlen(str);
    char temp;

    for (int i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;    
    }   
}

#define MAX(a,b) ((a > b) ? a : b)

char * addStrings(char * num1, char * num2)
{
    int sz = MAX(strlen(num1), strlen(num2)) + 2;
    char* strSum = (char*)malloc(sz);

    reverseString(num1);
    reverseString(num2);

    int carry = 0, i=0;

    while(*num1 || *num2 || carry) {
        int sum = 0;

        if(*num1) {
            sum += (int)(*num1) - '0';
            num1++;
        }

        if(*num2) {
            sum += (int)(*num2) - '0';
            num2++;
        }

        sum += carry;
        carry = sum / 10; 
    
        strSum[i] = ((char)(sum%10) + '0');
        i++;
    }   
    strSum[i] = '\0';
    reverseString(strSum);
    return strSum;
}
