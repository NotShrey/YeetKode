class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        int i = 0, j = 0;
        int n3 = (n1 + n2);

        int ind2 = (n3 / 2);
        int ind1 = ind2 - 1;

        int cnt = 0;

        int EL1 = +1, EL2 = -1;

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == ind1) {
                    EL1 = nums1[i];
                }
                if (cnt == ind2) {
                    EL2 = nums1[i];
                }
                cnt++;
                i++;
            } else {
                if (cnt == ind1) {
                    EL1 = nums2[j];
                }
                if (cnt == ind2) {
                    EL2 = nums2[j];
                }
                cnt++;
                j++;
            }
        }

        while (i < n1) {
            if (cnt == ind1) {
                EL1 = nums1[i];
            }
            if (cnt == ind2) {
                EL2 = nums1[i];
            }
            cnt++;
            i++;
        }

        while (j < n2) {
            if (cnt == ind1) {
                EL1 = nums2[j];
            }
            if (cnt == ind2) {
                EL2 = nums2[j];
            }
            cnt++;
            j++;
        }

        if (n3 % 2 == 1) {
            return EL2;
        } else {
            return (double) ((double) (EL1 + EL2)) / 2.0;
        }
    }
}
