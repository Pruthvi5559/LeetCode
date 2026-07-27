//424. Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        int left = 0, right = 0;

        int maxlen = 0;

        // Frequency of characters in the current window
        vector<int> freq(26, 0);

        // Maximum frequency of a single character in the current window
        int maxCount = 0;

        while (right < n) {

            // Include current character in the window
            freq[s[right] - 'A']++;

            // Update the highest frequency character
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // Shrink the window if replacements needed exceed k
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update the maximum valid window length
            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};