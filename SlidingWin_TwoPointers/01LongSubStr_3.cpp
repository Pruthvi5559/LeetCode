//3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0, right = 0;
        int n = s.size();

        // Stores the last index of each character
        vector<int> hash(256, -1);

        int maxlen = 0, len = 0;

        while (right < n) {

            // If character is already seen within the current window,
            // move the left pointer just after its last occurrence
            if (hash[s[right]] != -1) {
                if (hash[s[right]] >= left) {
                    left = hash[s[right]] + 1;
                }
            }

            // Current window length
            len = right - left + 1;

            // Update maximum length
            maxlen = max(len, maxlen);

            // Store the latest index of the current character
            hash[s[right]] = right;

            right++;
        }

        return maxlen;
    }
};