int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*1000);
    int pos = 0;
    bool visited[1001] = {false};
    for(int i = 0 ; i < nums1Size ; i++){
        visited[nums1[i]] = true;
    }
    for(int i = 0 ; i < nums2Size ; i++){
        if(visited[nums2[i]]){
            ans[pos++] = nums2[i];
            visited[nums2[i]] = false;
        }
    }
    *returnSize = pos;
    return ans;
}
