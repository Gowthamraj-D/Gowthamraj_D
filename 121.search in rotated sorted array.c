

int search(int* nums, int numsSize, int target){
int i,value;;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            value=i;
         ;
        break;
        }
        else value= -1;
    }
    return value;
    
}
