void moveZeroes(int* nums, int numsSize){
    int x=0;
    int temp=0;
    for(int y =0;y<numsSize;++y){
        if (nums[y]!=0){
            temp=nums[x];
            nums[x]=nums[y];
            nums[y]=temp;
            ++x;
        }
        
    }
    
}
