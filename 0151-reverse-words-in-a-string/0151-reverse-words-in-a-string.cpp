class Solution {
public:
    string reverseWords(string s) {
        string result;
        
        int i = 0, n = s.length();
        
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) {
                break;
            }
            int j = i + 1;
            while (j < n && s[j] != ' ') {
                j++;
            }
            string sub = s.substr(i, j - i);
            if (result.length() == 0) {
                result = sub;
            } else {
                result = sub + (result.empty() ? "" : " ") + result;
            }
            i = j + 1;
        }
        return result;
    }
};





//class Solution {
// public:
//     string reverseWords(string s) {

//         reverse(s.begin(),s.end());
//         int l = 0 , r= 0, i = 0,n = s.size();
        
//         while(i<r){
//             while(i<n && s[i]!=' ')
//                 s[r]=s[i];
//                 r++;
//                 i++;
//         }
//         if(l<r){
//             reverse(s.begin()+1,s.begin()+r); // rev current word
//             if(r == n){
//                 break;
//             }
//             s[r++]=' '
//         }
//     }
// };


