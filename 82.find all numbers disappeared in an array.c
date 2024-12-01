/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0, c = 0;
    int t2 = 0;
    while (i < numsSize) {
        int t = nums[i];
        nums[i] = 0;
        if (t == i + 1) {
            nums[i] = t;
        } else {
            // Start Sorting
            while (t != 0) {
                // Save next number
                t2 = nums[t - 1];
                if (nums[t - 1] != t) {
                    // Insert Target Number
                    nums[t - 1] = t;
                } else {
                    // Collision Occurred
                    c++;
                    break;
                }
                // Update to next target value
                t = t2;
            }
        }
        i++;
    }

    // Build Solution
    *returnSize = c;
    i = 0;
    t2 = 0;
    while (i < numsSize) {
        if (nums[i] == 0) {
            nums[t2++] = i + 1;
        }
        i++;
    }
    return nums;
}
