// 2pointer apprch tc-> o(n log n) for sorting + o(n)*(n);
//sc-> 0(n) 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());    //Sorted Array
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int low = i + 1 , high = nums.size() - 1;   //Make two pointers high and low, and initialize sum as 0.
            int sum = 0;
            while(low < high){                          //Search between two pointers, just similiar to binary search.
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0){   //If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
                    high--;
                } else if(sum < 0){ //If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
                    low++;
                } else {
                    answer.push_back({nums[i] , nums[low] , nums[high]});  //we have found the required triplet, push it in answer vector
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(low < high && nums[low] == last_low_occurence){   // Update the low and high with last occurences of low and high.
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return answer;      //Return the answer vector.
    }
};









// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<vector<int>> ans;
        
//         sort(nums.begin(),nums.end());
        
//         for(int i= 0;i<n;i++){
//             if(i>0 && nums[i]==nums[i-1]){
//                 continue;
//             }
            
//             int j = i+1,  k = n-1;
            
//             while(j<k){
//                 int sum = nums[i]+nums[j]+nums[k];
                
//                 if(sum<0){
//                     j++;
//                 }
//                 else if(sum>0){
//                     k--;
//                 }
//                 else{
//                     vector<int> temp = {nums[i],nums[j],nums[k]};
//                     ans.push_back (temp);
//                     j++;
//                     k--;
                    
                    
//                     while(j<k && nums[j] == nums[j+1]){
//                         j--;
//                     }
//                     while(j<k && nums[k]== nums[k-1]){
//                         k++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };






















// this does not work;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();

//         set<vector<int>> st; // A set to store the unique triplets found.

//         for (int i = 0; i < n; i++) {
//             // Create a hashset to store the elements seen so far.  
//             set<int> hashset;

//             // Iterate over the remaining elements in the array.
//             for (int j = i + 1; j < n; j++) {
//                 // Calculate the third element required to form a triplet with `nums[i]` and `nums[j]`.
//                 int third = -(nums[i] + nums[j]);

//                 // If the third element is present in the hashset, then we have found a triplet.
//                 if (hashset.find(third) != hashset.end()) {
//                     // Create a vector to store the triplet.
//                     vector<int> temp = {nums[i], nums[j], third};

//                     // Sort the vector in ascending order.
//                     sort(temp.begin(), temp.end());

//                     // Insert the triplet into the set.
//                     st.insert(temp);
//                 }

//                 // Add the current element to the hashset.
//                 hashset.insert(nums[j]);
//             }
//         }

//         // Convert the set of triplets to a vector.
//         vector<vector<int>> ans(st.begin(), st.end());

//         return ans;
//     }
// };
