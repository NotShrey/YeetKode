// tc (log n) sc(1)


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int ans = INT_MAX;

        while (l <= h) {
            int mid = (h+l) / 2;// this l+h-l/2 didnt work here id why
            if (nums[l] <= nums[mid]) {
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
                h = mid - 1;
                ans = min(ans, nums[mid]);
                
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int sm = INT_MAX;

//         for(int i = 0;i<nums.size();i++){
//             if(nums[i]<sm){
//                 sm = nums[i];
//             }
//         }
//         return sm;
        
//     }
// };
// //o(n) could be better kal karunga bs laga ke