// class Solution {
//     public int findPeakElement(int[] nums) {
//         int n = nums.length;

//         if(n==1){
//             return 0;
//         }
//         if(nums[0]>nums[1]){ // 1>2
//             return nums[1];
//         }

//         if(nums[n-1]>nums[n-2]){
//             return nums[n-1];
//         }

//         int l = 1;
//         int h = n-1;
//         //7 10 5

//         while(l<=h){
//             int mid = l+(h-l)/2;
//             if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                
//                 return mid;
//             }
//             else if(nums[mid]>nums[mid-1]){ //10 > 7
//                 l = mid+1;
//             }
//             else if (nums[mid]>nums[mid+1]){
//                 h = mid+1;
//             }
//             else{
//                 l = mid +1;
//             }
//         }
//         return -1;
        
//     }
// }


class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;

        if (n == 1) {
            return 0; // There's only one element, which is a peak.
        }

        int l = 0;
        int h = n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2; // Calculate the middle index to avoid overflow.

            // Check if mid is a peak element
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }

            // If the element to the right is greater, move right
            if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else { // Otherwise, move left
                h = mid - 1;
            }
        }

        return -1; // No peak element found
    }
}
