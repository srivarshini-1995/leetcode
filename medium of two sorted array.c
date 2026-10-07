#include <math.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    
    while (low <= high) {
        int partition1 = low + (high - low) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        
        // Edge cases: if partition is 0, use INT_MIN. If partition is at the end, use INT_MAX.
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
        
        // Check if correct partition is found
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If total length is odd
            if ((m + n) % 2 != 0) {
                return (double)MAX(maxLeft1, maxLeft2);
            }
            // If total length is even
            return ((double)MAX(maxLeft1, maxLeft2) + MIN(minRight1, minRight2)) / 2.0;
        } 
        // We are too far right in nums1, need to move left
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } 
        // We are too far left in nums1, need to move right
        else {
            low = partition1 + 1;
        }
    }
    
    return 0.0;
}
