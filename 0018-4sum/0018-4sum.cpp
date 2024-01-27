class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                 set<long long> set;
                 for(int k=j+1; k<n; k++){
                    long long sum = nums[i] + nums[j];
                    sum+= nums[k];
                    long long req = target - sum;
                    if(set.find(req) != set.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)(req)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    set.insert(nums[k]);
                 }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
    }
};