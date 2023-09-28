
class Solution {
    // this func is used to find the high or the upper val or bound in which we will perform bs
    private int maximum(int[] piles) {
        int n = piles.length;
        int maxi = Integer.MIN_VALUE; 
        
        for (int i = 0; i < n; i++) {
            maxi = Math.max(maxi, piles[i]);
        }
        return maxi;
    }
    
    // calculating every possible eating capacity in that range
    private int calculate(int[] piles, int h) {
        int ans = 0;
        int n = piles.length;
        for (int i = 0; i < n; i++) {
            ans += Math.ceil((double) piles[i] / h);
        }
        return ans; 
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low = 0; 
        int high = maximum(piles); 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int total = calculate(piles, mid);

            if (total <= h) { // If we can finish within h hours, we can potentially reduce the speed
                high = mid - 1;
            } else { // If it takes more than h hours, we need to increase the speed
                low = mid + 1;
            }
        }
        return low;
    }
}

