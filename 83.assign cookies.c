void insertionsort(int * arr, int size){
    int key, j;
    for(int i=1; i<=size-1; i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int max=0;
    int i=0, j=0;
    if(gSize==1 || sSize==1){
        return 1;
    }

    insertionsort(g, gSize);
    insertionsort(s, sSize);
    while(i<gSize && j<sSize){
        if(s[j]>=g[i]){
            max++;
            i++;
        }
        j++;
    }  
    return max;
}
