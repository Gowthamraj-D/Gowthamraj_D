int com_pare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findLHS(int* nums, int numsSize){
int max = 0 ;
qsort(nums, numsSize , sizeof(int) , com_pare);
int arr[20005], o = 0, loc = 0, check[20005], p = 0;
check[p] = nums[0];
p++;
long long int k = nums[0];

for(int i = 0 ; i <numsSize ; i++)
{
    if(k==nums[i])
    {
        k = nums[i];
        loc++;
    }
    else
    {
        arr[o] = loc;
        o++;
        loc = 1 ;
        check[p] = nums[i];
        p++;
        k = nums[i];
    }
}
arr[o] = loc;
o++;

for(int i = 0 ; i < p-1 ; i++)
{
    if(check[i+1]-check[i] == 1)
    {
        if(arr[i]+arr[i+1] > max)
        {
            max = (arr[i]+arr[i+1]);
        }
    }
}


return max;

}
