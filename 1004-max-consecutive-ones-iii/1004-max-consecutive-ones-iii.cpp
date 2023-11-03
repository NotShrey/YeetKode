class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        int n = nums.size();
        int l = 0;
        int zerosCount = 0;

        for(int r = 0; r < n ; r++){
            if(nums[r]==0){
                zerosCount++;
            }
            while(zerosCount>k){
                if(nums[l]==0){
                    zerosCount--;
                }
                l++;
            }
            len = max(len,r-l+1);
        }
        return len;
    }
};
