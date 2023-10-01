class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = n1;

        int n = n1 + n2;

        while (low <= high) {
            int mid1 = (low + high) / 2; 
            int mid2 = (n + 1) / 2 - mid1; 

            int l1, l2, r1, r2;

            if (mid1 == 0) {
                l1 = INT_MIN;
            } else {
                l1 = nums1[mid1 - 1];
            }

            if (mid2 == 0) {
                l2 = INT_MIN;
            } else {
                l2 = nums2[mid2 - 1];
            }

            if (mid1 == n1) {
                r1 = INT_MAX;
            } else {
                r1 = nums1[mid1];
            }

            if (mid2 == n2) {
                r2 = INT_MAX;
            } else {
                r2 = nums2[mid2];
            }

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) {
                    return max(l1, l2); 
                } else {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0; 
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};















// //merge sort o(m+n) tc and o(n) sc

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> nums3; 
        
//         int n1 = nums1.size();
//         int n2 = nums2.size();
        
//         int i = 0, j = 0;
        
//         while (i < n1 && j < n2) {
//             if (nums1[i] <= nums2[j]) {
//                 nums3.push_back(nums1[i++]);
//             } else {
//                 nums3.push_back(nums2[j++]);
//             }
//         }
        
//         while (i < n1) {
//             nums3.push_back(nums1[i++]);
//         }
        
//         while (j < n2) {
//             nums3.push_back(nums2[j++]);
//         }
        
//         int n = n1 + n2;
        
//         if (n % 2 == 1) {
//             return static_cast<double>(nums3[n / 2]); // Median for odd number of elements
//         } else {
//             // Median for even number of elements is the average of the two middle elements
//             int middle1 = nums3[n / 2 - 1];
//             int middle2 = nums3[n / 2];
//             return static_cast<double>(middle1 + middle2) / 2.0;
//         }
//     }
// };
