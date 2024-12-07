int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void nextPermutation(int* nums, int numsSize)
{
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            int min = i;
            for (int j = i; j < numsSize; j++) {
                if (nums[i - 1] < nums[j] && nums[min] > nums[j]) {
                    min = j;
                }   
            }
            int t = nums[i - 1];
                nums[i - 1] = nums[min];
                nums[min] = t;
            qsort(nums + i, numsSize - i, sizeof(int), cmp);
            return;
        }
    } 
    qsort(nums, numsSize, sizeof(int), cmp);
}
