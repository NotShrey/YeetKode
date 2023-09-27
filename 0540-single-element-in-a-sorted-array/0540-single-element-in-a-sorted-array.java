class Solution {
    public int singleNonDuplicate(int[] nums) {

        int high = nums.length-1;
        int low = 0;
    
        //for boundary cases
        if(high==0)// if there is only one element given
        return nums[0];
        
        else if(nums[0]!=nums[1])// to check the if the single element is in 0th index
        return nums[0];
        
        else if(nums[high]!=nums[high-1])// to check if the single element is in the last index
        return nums[high];

        while(low<=high){
           int mid = (low+high)/2;
            //unique element condition
            if( nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])// 3 3 4 5 5 
            return nums[mid];

//            (even,odd) if the index mid is even then check if its next element is same or not 
//            || (odd,even) and index mid is pointing to odd index and check mid to its previous element
            if(((mid%2)==0 && nums[mid]==nums[mid+1]) ||((mid%2)==1 && nums[mid]==nums[mid-1]))
            low = mid+1;
            else
            high = mid-1;
        }       
        return -1; 
    }
};

// (even,odd) = element is in right half
// (odd,even) = element is in left half