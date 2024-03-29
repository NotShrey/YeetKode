class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans = 1e18;
        
        sort(beans.begin(),beans.end());
        
        long long n = beans.size();
        
        long long sum = 0;
        
        for(long long i = 0;i<n;i++){
            sum += beans[i];
        }
        
        for(long long i = 0 ;i<n;i++){
            long long change = sum -(n-i) * (long long)beans[i];
            ans = min(ans,change);
        }
        return ans;
        
    }
};