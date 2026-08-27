// 2904. Shortest and Lexicographically Smallest Beautiful String
/*You are given a binary string s and a positive integer k.
A substring of s is beautiful if the number of 1's in it is exactly k.
Let len be the length of the shortest beautiful substring.
Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a beautiful substring, return an empty string.
A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {
            // Count the current 1
            if (s[right] == '1')
                ones++;

            // Shrink the window while it has k ones
            while (ones == k) {
                int len = right - left + 1;
                string curr = s.substr(left, len);

                // Update answer if this substring is shorter
                // or lexicographically smaller for the same length
                if (len < minLen || 
                    (len == minLen && curr < ans)) {
                    minLen = len;
                    ans = curr;
                }

                // Remove the left character
                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};