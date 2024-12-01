int countSegments(char* s) {
   int num_seg = 0;
   int len = strlen(s);
    for(int i = 0; i<len; i++){
      if(s[i] != ' '){
        num_seg++; 
          while(s[i] != ' ' && i < len){
            i++;
          }
      }
        
    }
    return num_seg;
}
