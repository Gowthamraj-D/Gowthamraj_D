int myAtoi(char * s){
    int_fast64_t num = 0;
    bool neg = false;
    
    for (; isspace(*s) ; ++s);
    if (!isdigit(*s))
    {
        if (*s == '-') neg = true;
        else if (*s != '+') return num;
        ++s;
    }
    
    for (; *s == '0'; ++s);
    for (int_fast8_t i = 0; i < 12 && isdigit(*s) ; ++s, ++i) num = (num * 10) + (*s - '0');
    
    if (num > INT_MAX) return (neg) ? INT_MIN : INT_MAX;
    
    return (neg) ? -num : num;
}
