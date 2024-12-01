/*
 * 492. Construct the Rectangle
 *
 * A web developer needs to know how to design a web page's size. 
 * So, given a specific rectangular web page’s area, your job by 
 * now is to design a rectangular web page, whose length L and 
 * width W satisfy the following requirements:
 *
 * The area of the rectangular web page you designed must equal to the given target area.
 * The width W should not be larger than the length L, which means L >= W.
 * The difference between length L and width W should be as small as possible.
 * Return an array [L, W] where L and W are the length and width of the web 
 * page you designed in sequence.
 *
 * 1 <= area <= 10^7
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){

    /*
     * Input:
     *  area
     */

    int length = sqrt(area), width = length;
    int *ans = (int *)malloc(sizeof(int) * 2);

    *returnSize = 2;

    /*
     * Set length = sqrt(area), width = sqrt(area) 
     *  if L * W is smaller than area, increase length
     *  if L * W is larger than area, decrease width
     */
    do {
        if (length * width < area) {
            length++;
        }
        else if (length * width > area) {
            width--;
        }

    } while (length * width != area);

    /*
     * Output:
     *  *returnSize
     *  Return an array [L, W] where L and W are the length and width 
     *  of the web page you designed in sequence.
     */

    ans[0] = length;
    ans[1] = width;

    return ans;
}
