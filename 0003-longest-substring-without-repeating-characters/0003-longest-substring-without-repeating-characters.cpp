class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int len = 0;
        int left = 0;
        unordered_set<char> set;

        for (int right = 0; right < n; right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            len = max(len, right - left + 1);
        }
        return len;
    }
};







































// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         if(n == 0) return 0;
//         int MaxAns = INT_MIN;
        
//         for(int i = 0; i<n ; i++){
//             unordered_set<int>set;
//             for(int j = i; j<n ;j++){
//                 if(set.find(s[j])!=set.end()){
//                     MaxAns = max(MaxAns,j-i);
//                     break;
//                 }
//                 set.insert(s[j]);
//             }
//         }
//         return MaxAns;
//     }
// };


