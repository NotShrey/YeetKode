// tc will be o(n) and sc will be o(1);

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int cnt1 = 0, cnt2 = 0;
        
        int elem1 = Integer.MIN_VALUE;
        int elem2 = Integer.MIN_VALUE;


        int n = nums.length;

        for(int i= 0;i<n;i++){
            if(cnt1 == 0 && elem2!= nums[i]){
                cnt1++;
                elem1 = nums[i];
            }
            else if (cnt2 == 0 && elem1 != nums[i]){
                cnt2++;
                elem2 = nums[i];
            }
            else if (nums[i]==elem1){
                cnt1++;
            }
            else if (nums[i]==elem2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
       List<Integer> ls = new ArrayList<>();
        cnt1 =0 ; cnt2 =0;
        for(int i = 0;i<n;i++){
            if(elem1 == nums[i]) cnt1++;
            if(elem2 == nums[i]) cnt2++;
        }
        int mini = (n/3)+1;

        if(cnt1>= mini){
            ls.add(elem1);
        }
        if(cnt2>= mini){
            ls.add(elem2);
        }
        Collections.sort(ls);
        return ls;
    }
}