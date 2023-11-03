class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        if (n == 0) return 0;

        int len = 0;
        int maxCount = 0;
        int l = 0;

        vector<int> charCount(26, 0);

        for (int r = 0; r < n; r++) {
            charCount[s[r] - 'A']++; // Update the count of the current character

            maxCount = max(maxCount, charCount[s[r] - 'A']); // Track the most frequent character in the current window

            // If the number of character replacements needed is more than k, slide the left pointer
            if ((r - l + 1 - maxCount) > k) {
                charCount[s[l] - 'A']--; // Reduce the count of the character at the left pointer
                l++; // Slide the left pointer
            }

            len = max(len, r - l + 1); // Calculate the maximum length of the substring
        }

        return len;
    }
};
