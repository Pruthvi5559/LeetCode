//3517. Smallest Palindromic Rearrangement I
class Solution {
public:
    string smallestPalindrome(string s) {
        // Store the frequency of each character ('a' to 'z')
        vector<int> freq(26, 0);

        // Count the occurrences of every character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // String to store the left half of the palindrome
        string left = "";

        // Variable to store the middle character (if the length is odd)
        char mid = '\0';

        // Build the left half in lexicographical order
        for (int i = 0; i < 26; i++) {

            // Add half of the occurrences of the current character
            left += string(freq[i] / 2, 'a' + i);

            // If a character has an odd frequency,
            // it will be placed in the middle
            if (freq[i] % 2) {
                mid = 'a' + i;
            }
        }

        // The right half is the reverse of the left half
        string right = left;
        reverse(right.begin(), right.end());

        // If there is no middle character (even length),
        // return left + right
        if (mid == '\0') {
            return left + right;
        }

        // Otherwise, return left + middle + right
        return left + mid + right;
    }
};