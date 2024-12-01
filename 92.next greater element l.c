int* nextGreaterElement(const int* nums1, int nums1Size, const int* nums2, int nums2Size, int* returnSize){
    int* ans = malloc(nums1Size * sizeof(int));

    for (int i = 0, k = 0; i < nums1Size; i++, k++) {
	// fill resulting array with -1
        ans[k] = -1;
        bool isFound = false;
		
        for (int j = 0; j < nums2Size; j++) {
		
		// set the flag if we found a match
            if (nums1[i] == nums2[j])
                isFound = true;
				
		// if flag is set check if we got greater element
            if (isFound && nums1[i] < nums2[j]) {
                ans[k] = nums2[j];
                break;    
            }
        }
    }  
	
    *returnSize = nums1Size; 
    return ans;
}
