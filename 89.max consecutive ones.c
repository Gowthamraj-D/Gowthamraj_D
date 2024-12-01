int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int streak=0;
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
        {
            count++;
            if(count>=streak)
            streak=count;
        }
        else
        count=0;
    }
    return streak;
}
