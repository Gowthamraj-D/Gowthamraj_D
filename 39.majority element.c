int majorityElement(int* nums, int numsSize){
    int vote=0;
    int candidate=-1;
    for(int i=0;i<numsSize;i++)
    {
        if(vote==0)
        {
            candidate=nums[i];
            vote=1;
        }
        else
        {
            if(candidate==nums[i])
            vote++;
            else
            vote--;
        }
    }
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
    if(candidate==nums[i])
    count++;
    }
    if(count>numsSize/2)
    return candidate;
    else
    return -1;

}
