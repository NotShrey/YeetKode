class Solution {
public:
    int numberOfSubstrings(string s) {
        // O(N) time , O(1) space [because hasmap size is always 3]
        int left = 0 , right = 0 , n = s.size(),end = s.size()-1;
        unordered_map<char,int>mpp;
        int count = 0;

        while(right != n){
            mpp[s[right]]++;
            while(mpp['a'] && mpp['b'] && mpp['c']){
                count += 1+(end-right);
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.length();
//         int count = 0;

//         //abcabc
//         for (int i=0;i<n;i++){ //i = a  
//             for(int j=i;j<n;j++){ // (after 3 iterations) j = c
//                 string ans = s.substr(i,j-i+1);// here abc is stored
                
//                 bool HasA = false, HasB = false, HasC = false; 

//                 for(int k=0;k<ans.length();k++){// loop on abc
//                     char c = ans[k];// a then b then c
//                     if(c=='a') HasA = true; //these all become true
//                     if(c=='b') HasB = true;
//                     if(c=='c') HasC = true;
//                 }
//                 if(HasA && HasB && HasC){// after then increment count
//                     count++;
//                 }
//             }
//         }
//         return count;
        
//     }
// };