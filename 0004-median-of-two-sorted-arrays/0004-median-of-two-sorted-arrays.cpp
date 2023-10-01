//merge sort o(m+n) tc and o(n) sc

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3; 
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int i = 0, j = 0;
        
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                nums3.push_back(nums1[i++]);
            } else {
                nums3.push_back(nums2[j++]);
            }
        }
        
        while (i < n1) {
            nums3.push_back(nums1[i++]);
        }
        
        while (j < n2) {
            nums3.push_back(nums2[j++]);
        }
        
        int n = n1 + n2;
        
        if (n % 2 == 1) {
            return static_cast<double>(nums3[n / 2]); // Median for odd number of elements
        } else {
            // Median for even number of elements is the average of the two middle elements
            int middle1 = nums3[n / 2 - 1];
            int middle2 = nums3[n / 2];
            return static_cast<double>(middle1 + middle2) / 2.0;
        }
    }
};
