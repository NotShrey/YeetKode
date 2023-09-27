class Solution {

    private int bs(int []nums, int target, int low ,int high){

        if(low>high){
            return -1;
        }

          int mid = (low + high) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid]>target){
            return bs(nums,target,low,mid-1);
        }
        else{
            return bs(nums,target,mid+1,high);
        }
    }
    public int search(int[] nums, int target) {
    return bs(nums,target,0,nums.length-1);
        
    }
}