public class Solution {
    public int findD(int[] weights, int cap) {
        int day = 1;
        int load = 0;
        int n = weights.length;

        for (int i = 0; i < n; i++) {
            if (load + weights[i] > cap) {
                day++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();

        while (low <= high) {
            int mid = (low + high) / 2;
            int noOfDays = findD(weights, mid);
            if (noOfDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
