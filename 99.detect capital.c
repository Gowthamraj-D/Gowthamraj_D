bool detectCapitalUse(char * word){
    int i=0,first=0,second=0;
    if(strlen(word) == 1) return true;
    if(isupper(word[i++])) first=1;
    if(isupper(word[i])) second=1;
    while(word[i] != '\0'){
        if(isupper(word[i]) && first == 0) return false; // first is not upper but any other is
        if(isupper(word[i]) && second == 0) return false; // second is not upper but any other is
        if(!isupper(word[i]) && first == 1 && second == 1) return false; // first & second are upper but any other is not
        i++;
    }
    return true;
}
