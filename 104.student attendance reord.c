bool checkRecord(char* s) {
    short a=0, l=0;

    for(; *s!='\0'; s++) {
        if(l&&*s!='L'){ l=0; }
        switch(*s) {
            case 'A': a++; break;
            case 'L': l++; break;
            default: break;
        }
        if(a>=2||l>=3){ return false; }
    }

    return true;
}
