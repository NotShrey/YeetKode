class Solution {
    public int findKthPositive(int[] arr, int k) {
        int low = 0,high = arr.length-1;
        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid]-(mid+1); // 7 is mid - 7's index + 1 which is 3+1 = 4 
                                            // now missing will have the val as 7-4 = 3
            if(missing<k){                  // 3 is less than 5 is true so move right
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return k+high+1;
        
    }
}

// 0 1 2 3 4  array index
//[2,3,4,7,11]
// 1 2 3 4 5   default way


