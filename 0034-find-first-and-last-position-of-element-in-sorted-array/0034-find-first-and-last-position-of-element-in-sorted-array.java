class Solution {
    // for left side
    int lowerB(int[] nums, int target) {
        int n = nums.length;
        int l = 0;
        int h = n - 1;
        int first = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                first = mid;
                h = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return first;
    }
    //for right side

    int upperB(int[] nums, int target) {
        int n = nums.length;
        int l = 0;
        int h = n - 1;
        int last = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                last = mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return last;
    }

    public int[] searchRange(int[] nums, int target) {
        int f = lowerB(nums, target);
        if (f == -1) {
            return new int[]{-1, -1};
        }
        int l = upperB(nums, target);
        return new int[]{f, l};
    }
}
