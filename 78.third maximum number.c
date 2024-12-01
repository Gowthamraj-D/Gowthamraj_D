int thirdMax(int* nums, int numsSize) {
   int i,j,temp,point;
   int count = 1;
   for(i=0;i<numsSize;i++){
    for(j=i+1;j<numsSize;j++){
        if(nums[i]<nums[j]){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    //printf("%d ",nums[i]);
   } 
   if(numsSize < 3)
   return nums[0];
   for(i=0;i<numsSize-1;i++){
    if(nums[i]!=nums[i+1]){
        count++;
        printf("%d ",count);  
    }
    if(count == 3){
        point = i+1;
    }
   }
   if(count<3){
    return nums[0];
   }
   return nums[point];
return 0;
}
