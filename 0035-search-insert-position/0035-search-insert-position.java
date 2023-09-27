// same as lower bound

class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        int l = 0;
        int h = n - 1;
        int ans = n; // Default answer agar target is baada than all elements
        while (l <= h) {
            int mid = l + (h - l) / 2; 
            if (target <= nums[mid]) { // 2 < 3 left side
                ans = mid; // 1(index)
                h = mid - 1; // 0(index)
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}
