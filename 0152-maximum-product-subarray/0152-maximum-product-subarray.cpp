//tc -> o(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref= 1, suff = 1;
        
        int ans = INT_MIN;
        
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            
            pref *= nums[i];
            suff *= nums[n-i-1];
            ans = max(ans, max(pref,suff));
        }
        return ans;
    }
};


// //tc -> o(n^2)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//        int result = nums[0];
//     for(int i=0;i<nums.size()-1;i++) {
//         int p = nums[i];
//         for(int j=i+1;j<nums.size();j++) {
//            result = max(result,p);
//            p *= nums[j];
//         }
//         result = max(result,p);//manages (n-1)th term 
//     }
//     return result;  
//     }
// };




// //tc -> o(n^3)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//     int maxi = INT_MIN;
//     for(int i=0;i<nums.size()-1;i++) {
        
//         for(int j=i+1;j<nums.size();j++) {
            
//             int prod = 1;
            
//             for(int k=i;k<=j;k++) {
//                 prod *= nums[k];
//             }
//             maxi = max(maxi,prod);    
//         }
//     }
//     return maxi;
// }
// };