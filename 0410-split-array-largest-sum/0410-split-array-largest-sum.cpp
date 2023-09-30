class Solution {
private:
    int CntPaint(vector<int>& nums, int paint) {
        int painters = 1, walls = 0;
        
        for (int i = 0; i < nums.size(); i++) { 
            if (walls + nums[i] <= paint) {
                walls += nums[i];
            }
            else {
                painters++;
                walls = nums[i];
            }
        }
        return painters;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            int noOfPaint = CntPaint(nums, mid);
            if (noOfPaint <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
