// in order to get the smallest val without anny tailing zeros 
// we can first convert them into string then we can sort
// after that we can use somthing as find_first_not_of as it will get the next index if 1 or any no after 0
// if it is a -ve no then sort them in decending order and then just multipy -1 after it as it was string prv
// the time complexity is O(log(n) * log(log(n)), the space complexity is O(log(n)).

class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        
        if(num>=0){
            sort(s.begin(),s.end());
        }
        else{
            sort(s.begin(),s.end(),greater<char>());
        }
        
        if(num>0){
            int index = s.find_first_not_of('0');
            swap(s[0],s[index]);
        }
        long long ans = stoll(s);
        if(num<0){
            ans *=-1;
        }
        return ans;
        
    }
};