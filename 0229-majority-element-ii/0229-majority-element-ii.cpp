//better approach tc-> o(n) but sc -> log(n) because of odered map

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        map<int,int> mpp;
        
        int mini  = (n/3)+1;
        
        for(int i = 0;i<n;i++){
           int added = ++mpp[nums[i]];
            
            if( added == mini){
                ls.push_back(nums[i]);
            }
            if(ls.size()==2){
                break;
            }
        }
        sort(ls.begin(),ls.end());
        return ls;
    }
};





























// // brute force approach tc-> o(n^2)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ls;

//         for (int i = 0; i < n; i++) {
//             if (ls.size() == 0 || ls[0] != nums[i]) {
//                 int cnt = 0;
//                 for (int j = 0; j < n; j++) {
//                     if (nums[i] == nums[j]) {
//                         cnt++;
//                     }

//                     if (cnt > n / 3) {
//                         ls.push_back(nums[i]);
//                         break;
//                     }
//                 }
//             }

//             if (ls.size() == 2) {
//                 break;
//             }
//         }

//         return ls;
//     }
// };